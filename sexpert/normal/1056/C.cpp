#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main()
{
    int n, m, t, prevmove = 0;
    int powers[2005];
    vector<ii> badpairs;
    cin >> n >> m;
    for(int i = 1; i <= 2*n; i++)
        cin >> powers[i];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        badpairs.push_back({a, b});
    }
    cin >> t;
    t = 3 - t;
    bool done;
    for(int cturn = 0; cturn < 2*n; cturn++)
    {
        t = 3 - t;
        if(t == 1)
        {
            done = false;
            for(int i = 0; i < badpairs.size(); i++)
            {
                ii p = badpairs[i];
                if(p.first == prevmove || p.second == prevmove)
                {
                    cout << p.second + p.first - prevmove << endl;
                    cout.flush();
                    powers[p.first] = powers[p.second] = 0;
                    badpairs.erase(badpairs.begin() + i);
                    done = true;
                    break;
                }
            }
            if(done)
                continue;
            for(int i = 0; i < badpairs.size(); i++)
            {
                ii p = badpairs[i];
                if(p.first != 0 || p.second != 0)
                {
                    int ans = (powers[p.first] > powers[p.second]) ? p.first : p.second;
                    cout << ans << endl;
                    cout.flush();
                    powers[p.first] = powers[p.second] = 0;
                    badpairs.erase(badpairs.begin() + i);
                    done = true;
                    break;
                }
            }
            if(done)
                continue;
            int cpow = 0, ans = 0;
            for(int i = 1; i <= 2*n; i++)
            {
                if(powers[i] > cpow)
                {
                    cpow = powers[i];
                    ans = i;
                }
            }
            cout << ans << endl;
            cout.flush();
            powers[ans] = 0;
        }
        if(t == 2)
        {
            cin >> prevmove;
            powers[prevmove] = 0;
            if(prevmove == -1)
                exit(0);
        }
    }
}