// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,SQ=780;
const ll inf=1e18;

ll dp[2][SQ];
vector<int>v[maxn];
int n,m;
ll ans;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
	int a,b;scanf("%d%d",&a,&b);
	if((a=n+1-a)>=(SQ-1)) ans+=3;
	else v[b].PB(a);
    }
    for(int i=1;i<SQ;i++)
	dp[0][i]=inf;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
	dp[i&1][SQ-1]=inf;
	sort(v[i].begin(),v[i].end());
	int num=0;
	for(int j=SQ-2;j>=0;j--){// i taye aval be torike bedonim j taye paiini ok hastan
	    dp[i&1][j]=min(dp[i&1][j+1],num+min(dp[(i+1)&1][0]+(j==0?0:2)+1ll*((j*(j+1))/2),dp[(i+1)&1][j+1]));
	    if(!v[i].empty() && v[i].back()==j)
		num+=3,v[i].POB();
	}
    }
    ans+=dp[n&1][0];
    printf("%lld\n",ans);
}