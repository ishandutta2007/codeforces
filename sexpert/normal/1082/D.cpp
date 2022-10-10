#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, lv = 0, bigs = 0;
    cin >> n;
    vector<int> deg, locb, locl, neigh[502];
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        deg.push_back(d);
        if(d == 1)
        {
            lv++;
            locl.push_back(i);
        }
        else
        {
            bigs++;
            locb.push_back(i);
        }
    }
    if(bigs == 0)
    {
        cout << "NO\n";
        return 0;
    }
    if(bigs == 1)
    {
        int kl = deg[locb[0]];
        if(lv > kl)
        {
            cout << "NO\n";
            return 0;
        }
        cout << "YES ";
        if(lv == 1)
            cout << "1\n";
        else
            cout << "2\n";
        cout << n - 1 << endl;
        for(int i = 0; i < n; i++)
        {
            if(i == locb[0])
                continue;
            cout << locb[0] + 1 << " " << i + 1 << endl;
        }
        return 0;
    }
    if(lv == 0)
    {
        cout << "YES " << bigs - 1 << endl;
        cout << n - 1 << endl;
        for(int i = 0; i < n - 1; i++)
            cout << i + 1 << " " << i + 2 << endl;
        return 0;
    }
    if(lv == 1)
    {
        cout << "YES " << bigs << endl;
        cout << n - 1 << endl;
        cout << locl[0] + 1 << " " << locb[0] + 1 << endl;
        for(int i = 0; i < bigs - 1; i++)
            cout << locb[i] + 1 << " " << locb[i + 1] + 1 << endl;
        return 0;
    }
    int m = bigs;
    neigh[0].push_back(locl[0]);
    neigh[m - 1].push_back(locl[1]);
    deg[locb[0]]++;
    deg[locb[m - 1]]++;
    int indb = 0;
    for(int i = 2; i < locl.size(); i++)
    {
        while(indb < m && neigh[indb].size() == deg[locb[indb]] - 2)
            indb++;
        if(indb >= m)
        {
            cout << "NO\n";
            return 0;
        }
        neigh[indb].push_back(locl[i]);
    }
    cout << "YES " << bigs + 1 << endl;
    cout << n - 1 << endl;
    for(int i = 0; i < m; i++)
    {
        for(auto x : neigh[i])
            cout << locb[i] + 1 << " " << x + 1 << endl;
        if(i < m - 1)
            cout << locb[i] + 1 << " " << locb[i + 1] + 1 << endl;
    }
}