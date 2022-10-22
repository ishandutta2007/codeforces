#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99,mod=998244353;

int n,t,now,ans,a[N][2],cnt[10];
string s[N];

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n || k<0) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int check(string s,string t){
	if((s[0]=='?' || s[0]==t[0]) && (s[1]=='?' || s[1]==t[1])) return 1;
	return 0;
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	make_fac();
	cin>>n;
	f(i,0,n){
		cin>>s[i];
		if(s[i][1]!='?'){
			if(s[i][1]=='B') s[i][1]='W';
			else s[i][1]='B';
		}
		if(check(s[i],"WB") && (s[i][0]=='?' || s[i][1]=='?')){
			//eror(s[i]);
			cnt[0]++;
		}
		if(check(s[i],"BW") && (s[i][0]=='?' || s[i][1]=='?')){
			//eror(s[i]);
			cnt[1]++;
		}
		if(s[i]=="WB"){
			now--;
		}
		if(s[i]=="BW"){
			now++;
		}
	}
	f(i,0,n+1){
		//cout<<i<<" "<<cnt[0]<<" "<<i-now<<" "<<cnt[1]<<endl;
		Add(ans,C(i,cnt[0])*C(i-now,cnt[1])%mod);
	}
	int res=1;
	f(i,0,n){
		if((s[i][0]=='?') + (s[i][1]=='?') ==2){
			res=2ll*res%mod;
		}
		if((s[i][0]=='?') + (s[i][1]=='?')==1){
			res=res;
		}
		if((s[i][0]=='?') + (s[i][1]=='?')==0){
			if(s[i][0]!=s[i][1]){
				res=0;
			}
		}
	}
	Add(ans,mod-res);
	
	int mv=1;
	f(i,0,n){
		if(!check(s[i],"WW")){
			mv=0;
		}
	}
	Add(ans,mv);
	
	mv=1;
	f(i,0,n){
		if(!check(s[i],"BB")){
			mv=0;
		}
	}
	Add(ans,mv);
	cout<<ans;
}