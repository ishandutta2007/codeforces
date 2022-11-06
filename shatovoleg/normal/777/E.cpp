#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;

template<class t>
void reverse(vector<t> &arr)
{
    int l = 0, r = arr.size();
    --r;
    while (r > l)
    {
        swap(arr[l], arr[r]);
        --r;
        ++l;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<piii> arr(n);
    for (auto &x : arr)
        cin >> x.first.second >> x.first.first >> x.second;
    sort(arr.begin(), arr.end());
    reverse(arr);
    vector<piii> st;
    long long cur_h = 0, cur_max = -1;
    for (auto x : arr)
    {
        while (st.size() && (st.back().first.second >= x.first.first))
        {
            cur_h -= st.back().second;
            st.pop_back();
        }
        st.push_back(x);
        cur_h += x.second;
        cur_max = max(cur_max, cur_h);
    }
    cout << cur_max << endl;
}