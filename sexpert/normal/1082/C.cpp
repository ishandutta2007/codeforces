#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e10;
vector<long long> ls[100002];
vector<long long> tsum(100002);

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ls[x].push_back(y);
    }
    for(int i = 1; i <= m; i++)
    {
        ls[i].push_back(-INF);
        sort(ls[i].rbegin(), ls[i].rend());
        /*for(auto x : ls[i])
            cout << x << " ";
        cout << endl;*/
    }
    long long sum = 0, ans = 0;
    set<int> gind;
    for(int i = 1; i <= m; i++)
        gind.insert(i);
    stack<int> rem;
    for(int ht = 0; ht < 100002; ht++)
    {
        for(int x : gind)
        {
            if(ht >= ls[x].size())
                continue;
            tsum[x] = tsum[x] + ls[x][ht];
            sum += ls[x][ht];
            if(tsum[x] < 0)
            {
                rem.push(x);
                sum -= tsum[x];
            }
        }
        ans = max(ans, sum);
        while(!rem.empty())
        {
            int u = rem.top();
            rem.pop();
            gind.erase(u);
        }
    }
    cout << ans << endl;
}