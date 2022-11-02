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
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

LL n,ans;
int k,a[200],f[100000][100][3];

LL search(LL n,int k,int flag)
{
    if (n==0) return 0;
    if (n<100000)
    {
        if (f[n][k][flag]!=-1) return f[n][k][flag];
    }
    if (k==0) return n*flag; else
    {
        ans=search(n/a[k],k-1,flag*(-1))+search(n,k-1,flag);
        if (n<100000) f[n][k][flag]=ans;
        return ans;
    }
}

int main()
{
    for (int i=0;i<100000;i++)
        for (int j=0;j<100;j++)
            for (int k=0;k<3;k++)
                f[i][j][k]=-1;
    //freopen("E.in","r",stdin);
    cin>>n>>k;
    for (int i=1;i<=k;i++) cin>>a[i];
    sort(a+1,a+k+1);
    cout<<search(n,k,1)<<endl;

    return 0;
}