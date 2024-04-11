#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int MAXK = 10100;

int N;
int mval[MAXK];
vector <int> cloc[MAXK];

pair <int, int> q[MAXK];
int nq;

vector <int> ans;

bool bad (pair <int, int> x, pair <int, int> y, pair <int, int> z)
{
    ll a = x.first, b = x.second, c = y.first, d = y.second, e = z.first, f = z.second;
    return d * (b * e * (a - c) + a * f * (c - e)) < b * c * f * (a - e);
}

void add (pair <int, int> t)
{
    if (nq >= 1 && q[nq-1].second >= t.second) return;
    
    q[nq] = t;
    while (nq >= 2 && bad (q[nq-2], q[nq-1], q[nq]))
        q[--nq] = t;
    nq++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    for (int i = 0; i < MAXK; i++)
    {
        mval[i] = -1;
    }
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        
        if (mval[a] < b)
        {
            mval[a] = b;
            cloc[a].clear();
        }
        if (mval[a] == b)
            cloc[a].push_back(i+1);
    }
    
    nq = 0;
    for (int i = MAXK - 1; i >= 1; i--)
    {
        if (mval[i] < 0) continue;
        add (make_pair (i, mval[i]));
    }
    
    for (int i = 0; i < nq; i++)
    {
        for (int j = 0; j < cloc[q[i].first].size(); j++)
            ans.push_back (cloc[q[i].first][j]);
    }
    
    sort (ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}