#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int b[32]{0};
        int ans = n;
        set<int> st;
        st.insert(0);
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            x ^= a;
            if(st.find(x) != st.end())
            {
                ans--;
                st.clear();
                x = 0;
            }
            st.insert(x);
        }
        cout << ans << endl;
    }
}