#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
char s[100][100];
int ans[100][4];
int kind(char c)
{
    if(c >= '0' && c <= '9') return 0;
    if(c >= 'a' && c <= 'z') return 1;
    return 2;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=99;i++)
    {
        ans[i][0] = ans[i][1] = ans[i][2] = 100;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s", s[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int pos = min(j-1, m-j+1);
            ans[i][kind(s[i][j])] = min(pos, ans[i][kind(s[i][j])]);
        }
    }
    int res = 10000000;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            for(int k=1;k<=n;k++)
            {
                if(k==i||k==j) continue;
                res = min(ans[i][0] + ans[j][1] + ans[k][2], res);
            }
        }
    }
    cout << res << endl;
}