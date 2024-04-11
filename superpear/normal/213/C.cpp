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
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int n,xc,yc,xd,yd,xe,ye,xf,yf,pl;
int a[301][301],f[601][301][301],vi[3],vj[3];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=0;i<=600;i++)
        for (int j=0;j<=300;j++)
            for (int k=0;k<=300;k++)
                f[i][j][k]=-maxlongint;
    f[2][1][1]=a[1][1];
    vi[1]=1;vj[1]=0;
    vi[2]=0;vj[2]=1;
    for (int i=2;i<=n*2-1;i++)
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
                if (f[i][j][k]!=-maxlongint)
                {
                    xc=j;yc=i-j;
                    xd=k;yd=i-k;
                    for (int p=1;p<=2;p++)
                        for (int q=1;q<=2;q++)
                        {
                            xe=xc+vi[p];ye=yc+vj[p];
                            xf=xd+vi[q];yf=yd+vj[q];
                            if ((xe<=n)&&(ye<=n)&&(xf<=n)&&(yf<=n))
                            {
                                if (xe==xf) pl=a[xe][ye]; else pl=a[xe][ye]+a[xf][yf];
                                f[i+1][xe][xf]=max(f[i+1][xe][xf],f[i][j][k]+pl);
                            }
                        }
                }
    cout<<f[n*2][n][n]<<endl;
    return 0;
}