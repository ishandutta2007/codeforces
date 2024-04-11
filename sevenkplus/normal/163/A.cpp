#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 5010
#define P 1000000007
char s[N],t[N];int n,m,f[N][N],S=0;
int main()
{
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)f[i][j]=s[i]==t[j];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
        {
            if(s[i]==t[j])(f[i][j]+=f[i-1][j-1])%=P;
            (f[i][j]+=f[i][j-1])%=P;
        }
    for(int i=1;i<=n;i++)(S+=f[i][m])%=P;
    cout<<S<<endl;
    return 0;
}