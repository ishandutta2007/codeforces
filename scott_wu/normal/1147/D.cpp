#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 2100;
const ll MOD = 998244353;

int N;
string s;

bool bad;
bool seen[MAXN];
int cval[MAXN];
vector <pair <int, int> > edges[MAXN];

void flood (int x, int cv)
{
    //cout << x << " " << cv << "\n";
    if (seen[x])
    {
        if (cval[x] != cv)
        {
            bad = true;
        }
        return;
    }
    seen[x] = true;
    cval[x] = cv;
    for (pair <int, int> e : edges[x])
    {
        flood (e.first, cv ^ e.second);
    }
}

ll gogo()
{
    bad = false;
    int nc = 0;
    for (int i = 0; i < 2 * N + 2; i++)
    {
        if (!seen[i])
        {
            //cout << "gogo\n";
            flood (i, 0);
            nc++;
        }
    }
    if (bad) return 0;
    ll ans = 1;
    for (int i = 0; i + 1 < nc; i++)
    {
        ans = (2 * ans) % MOD;
    }
    return ans;
}

ll get_res (int M)
{
    for (int i = 0; i < MAXN; i++)
    {
        seen[i] = false;
        cval[i] = -1;
        edges[i].clear();
    }
    for (int i = 0; i < N; i++)
    {
        edges[i].push_back(make_pair(N-1-i, 0));
    }
    for (int i = 0; i < M; i++)
    {
        edges[N+i].push_back(make_pair(N+(M-1-i), 0));
    }
    for (int i = M; i < N; i++)
    {
        edges[N+i].push_back(make_pair(2*N, 0));
        edges[2*N].push_back(make_pair(N+i, 0));
    }
    edges[2*N].push_back(make_pair(2*N+1, 1));
    edges[2*N+1].push_back(make_pair(2*N, 1));

    for (int i = 0; i < N; i++)
    {
        char c = s[N-1-i];
        if (c == '0')
        {
            edges[i].push_back(make_pair(N+i, 0));
            edges[N+i].push_back(make_pair(i, 0));
        }
        else if (c == '1')
        {
            edges[i].push_back(make_pair(N+i, 1));
            edges[N+i].push_back(make_pair(i, 1));            
        }
    }

    // start with 1
    edges[0].push_back(make_pair(2*N+1, 0));
    edges[2*N+1].push_back(make_pair(0, 0));
    edges[N].push_back(make_pair(2*N+1, 0));
    edges[2*N+1].push_back(make_pair(N, 0));

    return gogo();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;
    N = s.length();

    ll ans = 0;
    for (int i = 1; i < N; i++)
    {
        ans = (ans + get_res (i)) % MOD;
    }
    cout << ans << "\n";
}