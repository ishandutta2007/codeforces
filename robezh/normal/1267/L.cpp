//
// Created by 54173 on 12/8/2019.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1000;
int n,l,k;
char a[maxn*maxn+1];
char res[maxn+1][maxn+1];
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin >> n >> l >> k;

    for (int i=1; i<=n*l; i++)
        cin >> a[i];

    a[0] = ' ';
    sort(a+1,a+1+n*l);
    memset(res, ' ',sizeof(res));

    int cnt = 0;
    int lastNewLetter = 1;
    for (int i=1; i<=l; i++) {
        for (int j = lastNewLetter; j <= k; j++) {
            cnt++;
            res[j][i] = a[cnt];
            if (a[cnt]!=a[cnt-1])
                lastNewLetter = max(lastNewLetter,j);
        }
    }

    for (int i=k+1; i<=n; i++)
        for (int j=1; j<=l; j++)
        {
            cnt++;
            res[i][j] = a[cnt];
        }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=l; j++)
            if (res[i][j]==' ')
            {
                cnt++;
                res[i][j] = a[cnt];
            }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=l; j++)
            cout << res[i][j];
        cout << '\n';
    }
    return 0;
}