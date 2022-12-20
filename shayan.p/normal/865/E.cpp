// Phoenix

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

const int maxn=15,maxt=(1<<14);
const ll inf=4e18;

int a[maxn],b[maxn],sm[maxt];
ll dp[maxt],ans=inf;

inline char to_ch(int num){
    if(num<10) return '0'+num;
    return 'a'+num-10;
}

inline string to_str(ll num,int dig){
    string s="";
    for(int i=0;i<dig;i++)
	s+=to_ch(num&15),num>>=4;
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    for(int i=0;i<sz(s);i++)
	a[sz(s)-1-i]=(s[i]<='9'?s[i]-'0':s[i]-'a'+10);
    int n=sz(s);
    for(int msk1=0;msk1<(1<<(n-1));msk1++){
	for(int i=0;i<n;i++){
	    b[i]=a[i];
	}
	for(int i=0;i<n-1;i++){
	    if(bit(msk1,i)){
		b[i]-=16;
		b[i+1]++;
	    }
	}
	bool bad=0;
	for(int i=0;i<n;i++){
	    bad|=abs(b[i])>15;
	}
	sm[0]=0;
	for(int msk=1;msk<(1<<n);msk++){
	    sm[msk]=sm[msk ^ (msk & -msk)]+b[__builtin_ctz(msk & -msk)];
	}
	if(!bad && sm[(1<<n)-1]==0){
	    dp[0]=0;
	    for(int msk=1;msk<(1<<n);msk++){
		dp[msk]=inf;
		for(int i=0;i<n;i++){
		    if(bit(msk,i) && 0<=sm[msk ^ (1<<i)]+b[i] && sm[msk ^ (1<<i)]+b[i]<16 && dp[msk ^ (1<<i)]!=inf){
			dp[msk]=min(dp[msk],dp[msk ^ (1<<i)]+1ll*sm[msk ^ (1<<i)]*(1ll<<(4*i)));
		    }
		}
	    }
	    ans=min(ans,dp[(1<<n)-1]);
	}
    }
    return cout<<(ans==inf?"NO":to_str(ans,n))<<endl,0;
}