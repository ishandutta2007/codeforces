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
const int MAXN = 110;

int N, M;
char ch[MAXN][MAXN];
int val[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> ch[i][j];
            val[i][j] = (ch[i][j] == 'B' ? 1 : -1);
        }
    
    int res = 0;
    for (int i = N - 1; i >= 0; i--)
        for (int j = M - 1; j >= 0; j--)
            if (val[i][j] != 0)
            {
                res++;
                int t = val[i][j];
                for (int k = 0; k <= i; k++)
                    for (int l = 0; l <= j; l++)
                        val[k][l] -= t;
            }
    
    cout << res << "\n";
    return 0;
}