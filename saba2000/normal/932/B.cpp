#include<bits/stdc++.h>
using namespace std;
int g[1000009];
int f[1000009][10];
main()
{
    for (int i =1; i<=1000000; i++)
    {
        int x = i,y=1;
        while(x>0)
        {
            if(x%10)y=y*(x%10);
            x/=10;
        }
        if(y==i) g[i]=i;else
        g[i]=g[y];
        for (int j = 1; j<=9; j++)
        {
           f[i][j]=f[i-1][j];
        }
        f[i][g[i]]++;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        cout<<f[r][k]-f[l-1][k]<<endl;
    }


}