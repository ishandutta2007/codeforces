#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int a[200005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<int> st;
        int last = 1000000004;
        for(int i = 0; i < n; i++)
        {
            if(a[i] < last)
            {
                st.insert(i);
                last = a[i];
            }
        }
        while(m--)
        {
            int k, d;
            cin >> k >> d;
            k--;
            a[k] -= d;
            auto itr = st.upper_bound(k);
            bool f = false;
            auto itr2 = itr;
            itr2--;
            if(a[*itr2] > a[k])
            {
                f = true;
            }
            while(itr != st.end())
            {
                if(a[*itr] >= a[k])
                {
                    itr = st.erase(itr);
                }
                else
                {
                    break;
                }
            }
            if(f)
            {
                st.insert(k);
            }
            cout << st.size() << " ";
        }
        cout << "\n";
    }
}