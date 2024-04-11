#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;
typedef long long ll;
int n,k;
int a[MAXN][MAXN];
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&n);
    bool f=true;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[0][i]);
        if(a[0][i]==1) {f=false; cnt++;}
    }
    if(!f) {printf("%d\n",n-cnt); return 0;}
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            a[i][j]=gcd(a[i-1][j],a[i-1][j+1]);
            if(a[i][j]==1)
            {
                printf("%d\n",n-1+i);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}