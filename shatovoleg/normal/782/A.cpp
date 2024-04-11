#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n <<= 1;
    int mx = 0;
    set<int> st;
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        if (st.count(v))
            st.erase(v);
        else
            st.insert(v);
        if (st.size() > mx)
            mx = st.size();
    }
    cout << mx << endl;
}