#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#define sqr(x) (x)*(x)
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
using namespace std;

int n,ans=0,c[1000001];
inline int getans(int x){
    if(x%4==1) return x-1;
    if(x%4==2) return 1;
    if(x%4==3) return x;
    return 0;
}

int main()
{
    //freopen("MF.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        ans=ans^x;
    }
    for(int i=1;i<=n;i++)
    {
        int y=n/i;
        if(y&1) ans=ans^getans(i);
        int x=n%i;
        c[x]++;
    }
    for(int i=n-1;i>=1;i--)
        c[i]=c[i]+c[i+1];
    for(int i=1;i<=n;i++)
        if(c[i]&1) ans=ans^i;
    printf("%d\n",ans);
    return 0;
}