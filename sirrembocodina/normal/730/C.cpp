#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

const int maxn = 5100;

vector<int> g[maxn];

vector<pair<int, int> > shops[maxn];

int n;

int _q(int start, int r, int a)
{
    vector<char> used(n + 1, 0);
    vector<int> d(n + 1, 0);
    deque<int> q;
    vector<pair<pair<int, int>, int> > vc;
    q.push_front(start);
    used[start] = 1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for(int i = 0; i < shops[v].size(); ++i)
            vc.push_back(make_pair(shops[v][i], d[v]));
        for(int i = 0; i < g[v].size(); ++i)
        {
            int tv = g[v][i];
            if(!used[tv])
            {
                used[tv] = 1;
                d[tv] = d[v] + 1;
                q.push_back(tv);
            }
        }
    }
    sort(vc.begin(), vc.end());
    int _left = -1, _right = n;
    while(_right - _left > 1)
    {
        int m = (_left + _right) / 2;
        long long left = a;
        int need = r;
        for(int i = 0; i < vc.size(); ++i)
        {
            if(vc[i].second > m) continue;
            if(vc[i].first.second <= need)
            {
                left -= 1LL * vc[i].first.first * vc[i].first.second;
                need -= vc[i].first.second;
            }
            else
            {
                left -= 1LL * vc[i].first.first * need;
                need = 0;
            }
        }
        if(need == 0 && left >= 0) _right = m;
        else _left = m;
    }
    long long left = a;
    int need = r;
    for(int i = 0; i < vc.size(); ++i)
    {
        if(vc[i].second > _right) continue;
        if(vc[i].first.second <= need)
        {
            left -= 1LL * vc[i].first.first * vc[i].first.second;
            need -= vc[i].first.second;
        }
        else
        {
            left -= 1LL * vc[i].first.first * need;
            need = 0;
        }
    }
    if(need == 0 && left >= 0) return _right;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int w;
    cin >> w;
    for(int i = 0; i < w; ++i)
    {
        int a, p, k;
        cin >> a >> k >> p;
        shops[a].push_back(make_pair(p, k));
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int v, r, a;
        cin >> v >> r >> a;
        int ans = _q(v, r, a);
        cout << ans << endl;
    }
    return 0;
}