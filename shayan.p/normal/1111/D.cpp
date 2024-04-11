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

const int maxn=1e5+10,mod=1e9+7,sigma=55;

int dp[maxn];
int cnt[sigma],ans[sigma][sigma],fac[maxn];
string s;

int WH(char ch){
    if('a'<=ch && ch<='z') return ch-'a';
    return 26+ch-'A';
}
void Add(int x){
    for(int i=maxn-1;i>=x;i--){
	dp[i]=(dp[i]+dp[i-x])%mod;
    }
}
void Erase(int x){
    for(int i=x;i<maxn;i++){
	dp[i]=(dp[i]-dp[i-x])%mod;
	if(dp[i]<0) dp[i]+=mod;
    }
}
int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fac[0]=1;
    for(int i=1;i<maxn;i++){
	fac[i]=1ll*i*fac[i-1] %mod;
    }
    cin>>s;
    for(char ch:s){
	cnt[WH(ch)]++;
    }
    dp[0]=1;
    for(int i=0;i<sigma;i++){
	if(cnt[i]==0) continue;
	Add(cnt[i]);
    }
    int cof=1ll*fac[sz(s)/2]*fac[sz(s)/2]%mod;
    bool IS=0;
    for(int i=0;i<sigma;i++){
	if(cnt[i]==0) continue;
	if(cnt[i]>(sz(s)/2)) IS=1;
	cof=1ll*cof*Pow(fac[cnt[i]],mod-2) %mod;
    }
    int ANS=1ll*dp[sz(s)/2]*cof %mod;
    for(int i=0;i<sigma;i++){
	for(int j=i+1;j<sigma;j++){
	    if(cnt[i]==0 || cnt[j]==0) continue;
	    Erase(cnt[i]);
	    Erase(cnt[j]);
	    Add(cnt[i]+cnt[j]);
	    ans[i][j]=1ll*cof*dp[sz(s)/2] %mod;
	    Erase(cnt[i]+cnt[j]);
	    Add(cnt[i]);
	    Add(cnt[j]);
	}
    }
    int q;cin>>q;
    while(q--){
	int A,B;cin>>A>>B;
	if(IS){
	    cout<<0<<"\n";
	    continue;
	}
	--A;--B;
	A=WH(s[A]);
	B=WH(s[B]);
	if(A==B) cout<<ANS<<"\n";
	else if(A<B) cout<<ans[A][B]<<"\n";
	else cout<<ans[B][A]<<"\n";
    }
}