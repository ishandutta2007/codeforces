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

const int maxn=2e5+10,mod=1e9;

ll ls[maxn];
pii arr[maxn];
int pl[maxn];
bool is[maxn];
vector<int>v[maxn];
ll a,b,c;
int n,m;

inline ll Sum(ll n){
    return ((n*(n+1))/2);
}

ll solve0(){
    ll ans=0;
    for(int i=0;i<n;i++)
	ans+=1ll*i*a*(1ll*(n-1-i)*(n-2-i)/2);
    for(int i=0;i<n;i++)
	ans+=1ll*i*c*(1ll*i*(i-1)/2);
    for(int i=0;i<n;i++)
	ans+=1ll*i*b*i*(n-1-i);
    return ans;
}

ll solve1(){
    ll ans=0,rm=0;
    for(int i=0;i<n;i++){
	fill(ls,ls+sz(v[i])+3,0);
	ll sm=Sum(n-1)-i;
	int pos=-1;
	for(int j=0;j<sz(v[i]);j++){
	    sm-=v[i][j];
	    int bf=j==0?0:v[i][j-1];
	    ls[j]=1ll*(j==0?0:ls[j-1])+Sum(v[i][j]-1)-(j==0?0:Sum(v[i][j-1]))-1ll*i*(bf<=i && i<=v[i][j]);
	    if(v[i][j]<i) pos=j;
	}
	ll smd=(pos==-1?0:ls[pos])+Sum(i-1)-(pos==-1?0:Sum(v[i][pos]));
	for(int j=0;j<sz(v[i]);j++){
	    if(v[i][j]<i){
		ll cnt1=v[i][j]-j,cnt2=i-v[i][j]-1-pos+j,cnt3=n-i-sz(v[i])+pos;
		ll num=1ll*a*(ls[j]+1ll*v[i][j]*(cnt2+cnt3))+1ll*b*(1ll*cnt1*v[i][j]+smd-ls[j]+1ll*i*cnt3)+1ll*c*(1ll*i*(cnt1+cnt2)+sm-smd);
		if(num&1) rm++,num--;
		ans+=num/2;
	    }
	    else{
		ll cnt1=i-1-pos,cnt2=v[i][j]-i-j+pos,cnt3=n-v[i][j]-sz(v[i])+j;
		ll num=1ll*a*(smd+1ll*i*(cnt2+cnt3))+1ll*b*(1ll*i*cnt1+ls[j]-smd+1ll*v[i][j]*cnt3)+1ll*c*(1ll*v[i][j]*(cnt1+cnt2)+sm-ls[j]);
		if(num&1) rm++,num--;
		ans+=num/2;
	    }
	}
    }
    ans+=rm/2;
    return ans;
}

ll solve2(){
    for(int i=0;i<n;i++)
	arr[i]={sz(v[i]),i};
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
	pl[arr[i].S]=i;
    ll ans=0;
    for(int k=0;k<n;k++){
	for(int u:v[k])
	    is[u]=1;
	for(int j:v[k]){
	    if(pl[k]<=pl[j])continue;
	    for(int i:v[j]){
		if(pl[j]<=pl[i])continue;
		if(is[i]) ans+=1ll*a*min(i,min(j,k))+1ll*b*(i+j+k-min(i,min(j,k))-max(i,max(j,k)))+1ll*c*max(i,max(j,k));
	    }
	}
	for(int u:v[k])
	    is[u]=0;
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%lld%lld%lld",&a,&b,&c);
    for(int i=0;i<m;i++){
	int a,b;scanf("%d%d",&a,&b);
	v[a].PB(b);v[b].PB(a);
    }
    for(int i=0;i<n;i++)
	sort(v[i].begin(),v[i].end());
    ll ans=solve0()-solve1()-solve2();
    unsigned long long ANS=(ans>=0?ans:(~(-ans))+1);
    printf("%llu\n",ANS);
    return 0;
}