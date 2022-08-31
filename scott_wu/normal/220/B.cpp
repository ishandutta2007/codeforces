#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int MAXC = 501;

int N, M;
int num[MAXN];
int numoc[MAXN];
int ps[MAXC][MAXN];
vector <int> poss;

int main()
{
    for (int i = 0; i < MAXN; i++)
        numoc[i] = 0;
    
    scanf ("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf ("%d", &num[i]);
        if (num[i] <= N)
            numoc[num[i]]++;
    }
    
    for (int i = 1; i <= N; i++)
        if (numoc[i] >= i)
        {
            poss.push_back (i);
            int loc = poss.size() - 1;
            
            ps[loc][0] = 0;
            for (int j = 0; j < N; j++)
            {
                ps[loc][j+1] = ps[loc][j];
                if (num[j] == i)
                    ps[loc][j+1]++;
            }
        }
    
    for (int i = 0; i < M; i++)
    {
        int l, r;
        scanf ("%d %d", &l, &r);
        
        int ans = 0;
        for (int j = 0; j < poss.size(); j++)
            if (ps[j][r] - ps[j][l-1] == poss[j])
                ans++;
        
        printf ("%d\n", ans);
    }
    //system ("Pause");
    return 0;
}