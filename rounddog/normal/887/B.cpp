#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[3][6],t,n,b[3][10];

int main()
{
    scanf("%d",&n);
    memset(a,-1,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i=0;i<n;i++)
        for (int j=0;j<6;j++)
            scanf("%d",&a[i][j]);
    for (int i=0;i<3;i++)
        for (int j=0;j<6;j++)
            if (a[i][j]>=0) b[i][a[i][j]]=1;
    t=0;
    for (int i=1;i<10;i++)
    {
        if (b[0][i]==0&&b[1][i]==0&&b[2][i]==0) {printf("%d\n",t);return 0;} else t++;
    }
    for (int i=1;i<10;i++)
        for (int j=0;j<10;j++)
        {
            bool f=false;
            for (int k=0;k<3;k++)
                for (int l=0;l<3;l++)
                    if (k!=l&&b[k][i]&&b[l][j]) f=true;
            if (!f) {printf("%d\n",t);return 0;} else t++;
        }
    return 0;
}