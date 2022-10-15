#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int cnt[MAXN],p2[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    p2[0]=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            cnt[j]++;
    for(int i=1;i<=n;i++) p2[i]=2LL*p2[i-1]%MOD;
    int ans=0;
    for(int i=1;i<=n;i++) 
        add(ans,1LL*cnt[i]*(i>=n-1?1:p2[n-i-1])%MOD);
    printf("%d\n",ans);
}