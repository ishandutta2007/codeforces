#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int b[200005];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        set<int> st;
        st.insert(-2000000000);
        st.insert(2000000000);
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            int x = *--st.lower_bound(b[i]);
            int y = *st.upper_bound(b[i]);
            if(i && b[i] != b[i - 1] && x != b[i - 1] && y != b[i - 1])
            {
                f = false;
            }
            st.insert(b[i]);
        }
        if (f)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}