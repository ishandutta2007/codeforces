#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[100][100],A,B,C,S=0;ll s[100][100];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    scanf("%d%d%d",&A,&B,&C);
    if(A>B)swap(A,B);
    if(A>C)swap(A,C);
    if(B>C)swap(B,C);
    for(int i=1;i<m;i++)
        for(int j=i+1;j<m;j++)
        {
            ll SA=s[n][i],SB=s[n][j]-s[n][i],SC=s[n][m]-s[n][j];
            if(SA>SB)swap(SA,SB);
            if(SA>SC)swap(SA,SC);
            if(SB>SC)swap(SB,SC);
            if(SA==A&&SB==B&&SC==C)S++;
        }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            ll SA=s[i][m],SB=s[j][m]-s[i][m],SC=s[n][m]-s[j][m];
            if(SA>SB)swap(SA,SB);
            if(SA>SC)swap(SA,SC);
            if(SB>SC)swap(SB,SC);
            if(SA==A&&SB==B&&SC==C)S++;
        }
    printf("%d\n",S);
    return 0;
}