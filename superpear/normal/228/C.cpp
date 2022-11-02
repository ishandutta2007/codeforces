#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;
const int base=3214567;
const int bignum=1843907;

int m,n,o,k,ans,nk,a[505][505],f[140][505][505],powc[1000],hash[1000],hh[505][505];
char ch;

bool equal(int cc,int x,int y)
{
    int nc=f[cc][0][0],e;
    for (int i=1;i<=nc;i++)
    {
        e=hh[x+i-1][y+nc-1]-hh[x+i-1][y-1]*powc[nc];
        if (e!=hash[i]) return 0;
    }
    return 1;
}

int main()
{
    powc[0]=1;
    for (int i=1;i<=990;i++) powc[i]=powc[i-1]*base;
    scanf("%d %d",&m,&n);
    memset(a,0,sizeof(a));
    scanf("%c",&ch);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%c",&ch);
            if (ch=='.') a[i][j]=0; else a[i][j]=1;
        }
        scanf("%c",&ch);
    }
    o=0;
    memset(f,0,sizeof(f));
    k=0;
    for (int ic=0;ic<=1;ic++)
        for (int jc=0;jc<=1;jc++)
        for (int kc=0;kc<=1;kc++)
        for (int sc=0;sc<=1;sc++)
        {
            ++o;
            f[o][0][0]=2;
            f[o][1][1]=ic;f[o][1][2]=jc;f[o][2][1]=kc;f[o][2][2]=sc;
            k=o;
            for (int e=2;e*2<=min(m,n);e*=2)
            {
                ++o;
                f[o][0][0]=e*2;
                for (int id=0;id<=1;id++)
                    for (int jd=0;jd<=1;jd++)
                        for (int xx=1;xx<=e;xx++)
                            for (int yy=1;yy<=e;yy++)
                                if (f[k][id+1][jd+1]==1) f[o][xx+id*e][yy+jd*e]=1;
                                else f[o][xx+id*e][yy+jd*e]=f[o-1][xx][yy];
            }
        }
    ans=0;
    for (int cc=1;cc<=o;cc++)
        if (f[cc][0][0]>2)
        {
            nk=f[cc][0][0];
            for (int i=1;i<=nk;i++)
            {
                hash[i]=0;
                for (int j=1;j<=nk;j++)
                    hash[i]=hash[i]*base+f[cc][i][j]+bignum;
            }
            for (int i=1;i<=m;i++)
            {
                hh[i][0]=0;
                for (int j=1;j<=n;j++)
                    hh[i][j]=hh[i][j-1]*base+a[i][j]+bignum;
            }
            for (int i=1;i<=m-f[cc][0][0]+1;i++)
                for (int j=1;j<=n-f[cc][0][0]+1;j++)
                    if (equal(cc,i,j)==1) ++ans;
        }
    cout<<ans<<endl;
    return 0;
}