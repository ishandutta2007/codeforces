#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        P p[102];
        for(int i = 0; i < n; i++)
        {
            cin >> p[i].first;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> p[i].second;
        }
        vector<P> ans;
        for(int i = 0; i < n; i++)
        {
            int l = i;
            for(int j = i; j < n; j++)
            {
                if(p[j] < p[l])
                {
                    l = j;
                }
            }
            if(l != i)
            {
                ans.push_back(P(l, i));
                swap(p[l], p[i]);
            }
        }
        bool f = true;
        for(int i = 0; i < n - 1; i++)
        {
            if(p[i].second > p[i + 1].second)
            {
                f = false;
            }
        }
        if(!f)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans.size() << endl;
            for(P p : ans)
            {
                cout << p.first + 1 << " " << p.second + 1 << endl;
            }
        }
    }
}