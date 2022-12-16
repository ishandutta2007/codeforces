// Wanna Hack? GL...

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

const int maxn=42,mod=1e9+7;
const ll inf=1e18;

ll DP[maxn][maxn],ans,dp[maxn],tmp[maxn];
int n,nxt[maxn][2],f[maxn];
bool bad[maxn][maxn];
string s;

void go(int msk){
    memset(tmp,0,sizeof tmp);
    for(int i=0;i<=sz(s);i++){
	if(msk==0 || msk==2) tmp[nxt[i][0]]+=dp[i];
	if(msk==1 || msk==2) tmp[nxt[i][1]]+=dp[i];
    }
    memcpy(dp,tmp,sizeof dp);
    dp[sz(s)]=0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>s;
    nxt[0][s[0]-'0']=1;
    for(int i=1;i<sz(s);i++){// f esh hesab shode // to bayad nxt va f baadia ro hesab koni
	f[i+1]=nxt[f[i]][s[i]-'0'];
	nxt[i][s[i]-'0']=i+1;
	nxt[i]['1'-s[i]]=nxt[f[i]]['1'-s[i]];
    }
    nxt[sz(s)][0]=nxt[f[sz(s)]][0];
    nxt[sz(s)][1]=nxt[f[sz(s)]][1];
    for(int i=1;i<sz(s);i++){// in prefix
	for(int j=sz(s)-i;j<sz(s);j++){// in suffix
	    string str=s.substr(0,i)+s.substr(sz(s)-j);
	    for(int k=0;k<=sz(str)-sz(s);k++){
		bad[i][j]|=(str.substr(k,sz(s))==s);
	    }
	}
    }
    for(int i=sz(s)-1;i>=0;i--){
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(int j=sz(s)-i;j<sz(s);j++)
	    go(s[j]-'0');
	for(int j=0;j<n-i;j++)
	    go(2);
	for(int j=0;j<sz(s);j++)
	    DP[i][j]=dp[j];
	for(int j=i+1;j<=sz(s);j++){
	    if(s.substr(sz(s)-j,i)==s.substr(sz(s)-i)){
		for(int k=0;k<sz(s);k++)
		    DP[i][k]-=DP[j][k];
	    }
	}
	for(int j=0;j<sz(s);j++){
	    if(!bad[j][i])
		ans-=DP[i][j];
	}
    }
    ans+=1ll<<n;
    return cout<<ans<<endl,0;
}