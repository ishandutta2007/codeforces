#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int p10[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    p10[0]=1;
    for(int i=1;i<=200000;i++) p10[i]=10LL*p10[i-1]%MOD; 
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int ans;
        if(i==n) ans=10;
        else
        {
            ans=180LL*p10[n-i-1]%MOD;
            if(i!=n-1) add(ans,810LL*(n-i-1)*p10[n-i-2]%MOD);
        }
        printf("%d ",ans);
    }
    return 0;
}