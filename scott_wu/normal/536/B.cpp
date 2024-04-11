#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const ll MOD = 1e9 + 7;

int N, M;
string P;
int y[MAXN], fail[MAXN];

bool good[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> P;
    for (int i = 0; i < M; i++)
    {
        cin >> y[i];
        y[i]--;
    }
    
    fail[0] = -1;
    for (int i = 1; i < P.length(); i++)
    {
        int cloc = fail[i-1];
        while (cloc > -1 && P[i] != P[cloc+1])
            cloc = fail[cloc];
        if (cloc == -1 && P[i] != P[0])
            cloc = -2;
        
        fail[i] = cloc + 1;
        //cout << fail[i] << "\n";
    }
    
    for (int i = 0; i < MAXN; i++)
        good[i] = false;
    int cloc = (int) P.length() - 1;
    while (cloc != -1)
    {
        good[cloc] = true;
        cloc = fail[cloc];
    }
    
    for (int i = 0; i < M - 1; i++)
    {
        int diff = (y[i+1] - y[i]);
        if (diff >= P.length())
            continue;
        
        if (!good[P.length()-1-diff])
        {
            cout << "0\n";
            return 0;
        }
    }
    
    int xloc = 0;
    ll res = 1;
    for (int i = 0; i < N; i++)
    {
        if (xloc < M-1 && y[xloc+1] == i)
            xloc++;
        
        if (xloc >= M || y[xloc] > i || y[xloc] + P.size() <= i)
        {
            //cout << i << " " << xloc << " " << y[xloc] << "\n";
            res = (26 * res) % MOD;
        }
    }

    cout << res << "\n";
    return 0;
}