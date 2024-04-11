#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int , int > ipair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 100179;

int n, a[N];
int prevGEQ[N], nextG[N];

int main()
{
    ios::sync_with_stdio(false);

    int q;
    cin >> n >> q;
    --n;
    int prev;
    cin >> prev;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[i] = abs(x - prev);
        prev = x;
    }

    /*cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];*/
        
    vector < int > st;
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && a[st.back()] < a[i])
            st.pop_back();
        prevGEQ[i] = (st.empty() ? -1 : st.back());
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && a[st.back()] <= a[i])
            st.pop_back();
        nextG[i] = (st.empty() ? n : st.back());
        st.push_back(i);
    }

    //for (int i = 0; i < n; ++i)
    //    cerr << i << ") " << a[i] << " " << prevGEQ[i] << " " << nextG[i] << "\n";
    
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        --r;
        ll ans = 0;
        for (int j = l; j <= r; ++j)
            ans += (ll)a[j] * (j - max(l - 1, prevGEQ[j])) * (min(r + 1, nextG[j]) - j);
        cout << ans << "\n";
    }

    return 0;
}