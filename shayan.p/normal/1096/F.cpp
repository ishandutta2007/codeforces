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

const int maxn=2e5+10,mod=998244353;

int a[maxn],ans=0;

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

struct fenwick{
    int sm[maxn];
    fenwick(){
	memset(sm,0,sizeof sm);
    }
    void add(int x,int num){
	while(x<maxn)
	    sm[x]+=num,x+=(x & -x);	
    }
    int ask(int x){
	int ans=0;
	while(x>0)
	    ans+=sm[x],x-=(x & -x);
	return ans;
    }
};fenwick fn[2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,cnt1=0,cnt2=0;cin>>n;
    for(int i=1;i<=n;i++){
	fn[1].add(i,1);
    }
    for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]==-1)
	    cnt2++;
	else
	    fn[1].add(a[i],-1);
    }
    for(int i=1;i<=n;i++){
	if(a[i]==-1){
	    cnt2--;
	    cnt1++;
	    continue;
	}
	int inv=Pow(cnt1+cnt2,mod-2);
	ans=(1ll*ans+(1ll*cnt1*(fn[1].ask(n)-fn[1].ask(a[i]))+1ll*cnt2*fn[1].ask(a[i]))%mod *inv)%mod;
	ans=(1ll*ans+fn[0].ask(n)-fn[0].ask(a[i]))%mod;
	fn[0].add(a[i],1);
    }
    ans=(1ll*ans+(1ll*(cnt1)*(cnt1-1))%mod * Pow(4,mod-2))%mod;
    cout<<ans<<endl;
}