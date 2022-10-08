#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int le=20,ri=21;char z[]="BRWY";
set<int> U;int a[7][8],P[4][4],L[10],R[10],A[10],B[10],T=-1,p[22][22];bool v[7][8],w[10][10],r2[7][8],d2[7][8],u[22];char s[13][15],S[13][15];
void add(int x,int y)
{
    static int t=0;
    P[x][y]=P[y][x]=t,L[t]=x,R[t]=y,t++;
}
bool f2(int x)
{
    if(x==ri)return 1;u[x]=1;
    for(int i=21;i>=0;i--)
        if(p[x][i]&&!u[i]&&f2(i)){p[x][i]--,p[i][x]++;return 1;}
    return 0;
}
void gg()
{
    int c[10],D[10][10],t=0;
    int h=0;for(int i=0;i<10;i++)h*=1000000007,h+=B[i];
    if(U.find(h)!=U.end())return;U.insert(h);
    memcpy(c,A,sizeof c),
    memset(D,0,sizeof D);
    for(int i=0;i<10;i++)
        D[i][i]=min(A[i],B[i]),t+=D[i][i]*2;
    if(28+t/2<=T)return;
    memset(p,0,sizeof p);
    for(int i=0;i<10;i++)
        if(A[i]>B[i])p[le][i]=A[i]-B[i];else
        if(A[i]<B[i])p[i+10][ri]=B[i]-A[i];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)if(w[i][j])
        {
            int u=min(p[le][i],p[j+10][ri]);
            p[le][i]-=u,p[j+10][ri]-=u,p[i][j+10]=28,t+=u,D[i][j]+=u;
        }
    for(;memset(u,0,sizeof u),f2(le);t++);
    if(t<=T)return;T=t;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)D[i][j]+=p[j+10][i];
    for(int i=0;i<7;i++)
        for(int j=0;j<8;j++)s[i*2][j*2]='.';
    for(int i=0;i<7;i++)
        for(int j=0;j<8;j++)if(r2[i][j])
        {
            int o=P[a[i][j]][a[i][j+1]];
            for(int k=0;k<10;k++)if(D[k][o])
            {
                D[k][o]--,c[k]--;
                if(a[i][j]==R[k]||a[i][j+1]==L[k])swap(L[k],R[k]);
                s[i*2][j*2]=z[L[k]],s[i*2][j*2+2]=z[R[k]];
                break;
            }
        }
    for(int i=0;i<7;i++)
        for(int j=0;j<8;j++)if(d2[i][j])
        {
            int o=P[a[i][j]][a[i+1][j]];
            for(int k=0;k<10;k++)if(D[k][o])
            {
                D[k][o]--,c[k]--;
                if(a[i][j]==R[k]||a[i+1][j]==L[k])swap(L[k],R[k]);
                s[i*2][j*2]=z[L[k]],s[i*2+2][j*2]=z[R[k]];
                break;
            }
        }
    for(int i=0;i<7;i++)
        for(int j=0;j<8;j++)if(s[i*2][j*2]=='.'&&r2[i][j])
            for(int k=0;k<10;k++)if(c[k])
                {c[k]--,s[i*2][j*2]=z[L[k]],s[i*2][j*2+2]=z[R[k]];break;}
    for(int i=0;i<7;i++)
        for(int j=0;j<8;j++)if(s[i*2][j*2]=='.'&&d2[i][j])
            for(int k=0;k<10;k++)if(c[k])
                {c[k]--,s[i*2][j*2]=z[L[k]],s[i*2+2][j*2]=z[R[k]];break;}
    memcpy(S,s,sizeof s);
}
void ff(int x,int y)
{
    if(x==7){gg();return;}
    if(y==8){ff(x+1,0);return;}
    if(v[x][y]){ff(x,y+1);return;}
    if(y<7&&!v[x][y+1])
        v[x][y]=v[x][y+1]=1,
        B[P[a[x][y]][a[x][y+1]]]++,
        s[x*2][y*2+1]='-',r2[x][y]=1,
        ff(x,y+1),
        v[x][y]=v[x][y+1]=0,
        B[P[a[x][y]][a[x][y+1]]]--,
        s[x*2][y*2+1]='.',r2[x][y]=0;
    if(x<6&&!v[x+1][y])
        v[x][y]=v[x+1][y]=1,
        B[P[a[x][y]][a[x+1][y]]]++,
        s[x*2+1][y*2]='|',d2[x][y]=1,
        ff(x,y+1),
        v[x][y]=v[x+1][y]=0,
        B[P[a[x][y]][a[x+1][y]]]--,
        s[x*2+1][y*2]='.',d2[x][y]=0;
}
int main()
{
    for(int i=0;i<7;i++)
    {
        char s[100];scanf("%s",s);
        for(int j=0;j<8;j++)
            if(s[j]=='B')a[i][j]=0;else
            if(s[j]=='R')a[i][j]=1;else
            if(s[j]=='W')a[i][j]=2;else
            if(s[j]=='Y')a[i][j]=3;
    }
    add(0,3),add(0,2),add(0,1),add(0,0),
    add(1,3),add(1,2),add(1,1),
    add(2,3),add(2,2),add(3,3);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(L[i]==L[j]||L[i]==R[j]||R[i]==L[j]||R[i]==R[j])w[i][j]=1;
    for(int i=0;i<10;i++)scanf("%d",A+i);
    memset(s,'.',sizeof s),ff(0,0);
    printf("%d\n",T);
    for(int i=0;i<13;puts(""),i++)
        for(int j=0;j<15;j++)putchar(S[i][j]);
    return 0;
}