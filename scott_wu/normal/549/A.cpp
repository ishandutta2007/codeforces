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
const int MAXN = 55;

int N, M;
char ch[MAXN][MAXN];

bool has (int a, int b, char c)
{
    return ch[a][b] == c || ch[a+1][b] == c || ch[a][b+1] == c || ch[a+1][b+1] == c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> ch[i][j];
    
    int res = 0;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M - 1; j++)
            if (has (i, j, 'f') && has (i, j, 'a') && has (i, j, 'c') && has (i, j, 'e'))
                res++;
    cout << res << "\n";
    return 0;
}