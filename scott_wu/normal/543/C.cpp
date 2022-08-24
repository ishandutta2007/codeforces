#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 22;
const int MAXP = (1 << 20) + 100;

int N, M;
string s[MAXN];
int ccost[MAXN][MAXN];

int dp[MAXP];
vector <pair <int, int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> ccost[i][j];
    
    int start = (1 << N) - 1;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            vector <int> poss;
            for (int k = 0; k < N; k++)
                if (s[k][i] == ('a' + j))
                    poss.push_back (k);
            
            if (poss.size() == 1)
                start &= ((1 << N) - 1 - (1 << poss[0]));
            else if (poss.size() > 1)
            {
                int tot = 0, hi = 0;
                int mask = 0;
                
                for (int k = 0; k < poss.size(); k++)
                {
                    tot += ccost[poss[k]][i];
                    hi = max (hi, ccost[poss[k]][i]);
                    mask += (1 << poss[k]);
                }
                
                mask = (1 << N) - 1 - mask;
                tot -= hi;
                v.push_back (make_pair (tot, mask));
                //cout << tot << " " << mask << "\n";
            }
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        int res = 1e9;
        for (int j = 0; j < M; j++)
            res = min (res, ccost[i][j]);
        
        int mask = (1 << N) - 1 - (1 << i);
        v.push_back (make_pair (res, mask));
    }
    
    for (int i = 0; i < MAXP; i++)
        dp[i] = 1e9;
    dp[start] = 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        int c = v[i].first, m = v[i].second;
        for (int j = 0; j <= start; j++)
            dp[j&m] = min (dp[j&m], dp[j] + c);
    }
    cout << dp[0] << "\n";
    return 0;
}