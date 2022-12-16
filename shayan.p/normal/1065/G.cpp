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

const int maxn=210,P1=911382323,P2=972663749,mod=1e9+9;
const ll inf=2e18;

string suf[maxn],pre[maxn],ans;
vector<pii>hs[maxn],hp[maxn],hans;
int pw1[maxn],pw2[maxn];
ll dp[maxn],k,pt;
int n,m;

pii Hash(vector<pii>&vec,int l,int r){
    if(l==0) return vec[r];
    int A=(1ll*vec[r].F-1ll*vec[l-1].F*pw1[r-l+1]) %mod;
    int B=(1ll*vec[r].S-1ll*vec[l-1].S*pw2[r-l+1]) %mod;
    if(A<0) A+=mod;
    if(B<0) B+=mod;
    return {A,B};
}

void Do(string &s,vector<pii>&vec){
    vec.clear();
    int A=0,B=0;
    for(int i=0;i<sz(s);i++){
	A=(1ll*A*P1+s[i])%mod;
	B=(1ll*B*P2+s[i])%mod;
	vec.PB({A,B});
    }
}

ll check(){
    Do(ans,hans);
    memset(dp,0,sizeof dp);
    if(ans=="0")
	dp[0]=1;
    if(ans=="1")
	dp[1]=1;
    for(int i=2;i<=n;i++){
	dp[i]=dp[i-1]+dp[i-2];
	for(int j=1;j<sz(ans);j++)
	    dp[i]+=(sz(suf[i-2])>=j && Hash(hs[i-2],sz(suf[i-2])-j,sz(suf[i-2])-1)==Hash(hans,0,j-1) && sz(pre[i-1])>=(sz(ans)-j) && Hash(hp[i-1],0,sz(ans)-j-1)==Hash(hans,j,sz(ans)-1));
	if(dp[i]>=inf) return inf;
    }
    return dp[n];
}

int main(){
    pw1[0]=pw2[0]=1;
    for(int i=1;i<maxn;i++){
	pw1[i]=1ll*pw1[i-1]*P1 %mod;
	pw2[i]=1ll*pw2[i-1]*P2 %mod;
    }
    cin>>n>>k>>m;
    suf[0]=pre[0]="0";
    suf[1]=pre[1]="1";
    hs[0].PB({int('0'),int('0')});
    hp[0].PB({int('0'),int('0')});
    hs[1].PB({int('1'),int('1')});
    hp[1].PB({int('1'),int('1')});
    for(int i=2;i<=n;i++){
	if(m>sz(suf[i-1]))
	    suf[i]=suf[i-2].substr(max(0,sz(suf[i-2])-m+sz(suf[i-1])))+suf[i-1];
	else
	    suf[i]=suf[i-1];
	if(m>sz(pre[i-2]))
	    pre[i]=pre[i-2]+pre[i-1].substr(0,min(sz(pre[i-1]),m-sz(pre[i-2])));
	else
	    pre[i]=pre[i-2];
	Do(pre[i],hp[i]);
	Do(suf[i],hs[i]);
    }
    for(int i=0;i<m;i++){
	if(!ans.empty() && (pt=pt+(sz(suf[n])>=sz(ans) && suf[n].substr(sz(suf[n])-sz(ans))==ans))==k) break;
	ans+="0";
	ll num=check();
	if(pt+num<k)
	    ans[sz(ans)-1]='1',pt+=num;
    }
    cout<<ans<<endl;
    return 0;
}