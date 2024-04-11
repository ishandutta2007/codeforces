// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int maxn=53,maxsum=5300;
const ll inf=1e18;
const ld eps=1e-15;

ll dp[maxn][maxsum],tmp[maxn][maxsum];

map<int,vector<int> >mp;
pii p[maxn];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
	scanf("%d",&p[i].F);
    for(int i=0;i<n;i++)
	scanf("%d",&p[i].S);
    for(int i=0;i<n;i++)
	mp[p[i].F].PB(p[i].S);
    memset(dp,63,sizeof dp);
    dp[0][0]=0;
    for(auto it=mp.rbegin();it!=mp.rend();it++){
	auto P=*it;
	vector<int>&vec=P.S;
	sort(vec.begin(),vec.end(),greater<int>());
	memset(tmp,63,sizeof tmp);
	for(int i=sz(vec);i<maxn;i++){
	    for(int j=0;j<maxsum;j++)
		tmp[i-sz(vec)][j]=dp[i][j];
	}
	int sm=0;
	for(int tl=0;tl<sz(vec);tl++){
	    sm+=vec[tl];
	    for(int i=sz(vec)-tl-1;i<maxn;i++){
		for(int j=0;j<maxsum;j++){
		    if(j+sm>=maxsum || (i-sz(vec)+2*tl+2)>=maxn)continue;
		    ll &A=tmp[i-sz(vec)+2*tl+2][j+sm],B=dp[i][j]+1ll*P.F*(tl+1);
		    A=min(A,B);
		}
	    }
	}
	for(int i=0;i<maxn;i++)
	    for(int j=0;j<maxsum;j++)
		dp[i][j]=tmp[i][j];
    }
    ld ans=inf;
    for(int i=0;i<maxn;i++){
	for(int j=1;j<maxsum;j++){
	    ans=min(ans,ld(dp[i][j])/ld(j));
	    if(ans==8){
		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		return 0;
	    }
	}
    }
    ans*=1000;
    ll ANS=ans;
    if(abs(ANS-ans)>eps) ANS++;
    printf("%lld\n",ANS);
    return 0;
}