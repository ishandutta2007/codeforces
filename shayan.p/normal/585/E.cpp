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

const int maxn=5e5,MAX=1e7+10,mod=1e9+7;
const ll inf=1e18;

int pr[MAX],mo[MAX];
int cnt[MAX],GCD[MAX],tw[maxn];

void go1(int n,int num,int nw=1){// GCD d += (GCD d +1)*(tw x -1 + 1)
    if(n==1){
	GCD[nw]=(1ll*(GCD[nw]+1)*num -1)%mod;
	return;
    }
    int p=pr[n];
    go1(n/p,num,nw);go1(n/p,num,nw*p);
}

int go2(int n,int nw=1){// tedad aadadi ke nesbat be n avalan ro dar miare
    if(n==1){
	return mo[nw]*GCD[nw];
    }
    int p=pr[n];
    return (go2(n/p,nw)+go2(n/p,nw*p))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fill(mo,mo+MAX,1);
    tw[0]=1;
    for(int i=1;i<maxn;i++){
	tw[i]=2ll*tw[i-1] %mod;
    }
    for(int i=2;i<MAX;i++){// can make it O(n)
	if(pr[i]==0){
	    for(int j=i;j<MAX;j+=i){
		pr[j]=i;
		mo[j]*=-1;
		if((j/i)%i==0) mo[j]=0;
	    }
	}
    }
    int n;cin>>n;
    while(n--){
	int x,y=1;cin>>x;
	while(x>1){
	    int p=pr[x];
	    while(x%p==0) x/=p;
	    y*=p;
	}
	cnt[y]++;
    }
    for(int i=1;i<MAX;i++){
	if(cnt[i]==0) continue;
	go1(i,tw[cnt[i]]);
    }
    int ans=0;
    ll Ones=0;
    for(int i=1;i<MAX;i++){
	Ones+=mo[i]*GCD[i];
    }
    Ones%=mod;
    for(int i=1;i<MAX;i++){
	if(cnt[i]==0) continue;
	ans=(1ll*ans+1ll*cnt[i]*(go2(i)-Ones))%mod;
    }
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}