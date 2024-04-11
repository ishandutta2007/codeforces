#include<bits/stdc++.h>
#define MAXN 250005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int fact[MAXN];
void add(int &a,int b) {a+=b; if(a>=m) a-=m;}
void dec(int &a,int b) {a-=b; if(a<m) a+=m;}
int main()
{
    scanf("%d%d",&n,&m);
    fact[0]=1;
    for(int i=1;i<=250000;i++) fact[i]=1LL*fact[i-1]*i%m;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        add(ans,1LL*(n-i+1)*fact[i]%m*(n-i+1)%m*fact[n-i]%m);
    }
    printf("%d\n",ans);
    return 0;
}