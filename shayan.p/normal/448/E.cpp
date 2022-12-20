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

const int maxn=1e5+10,LIM=1e5;

map<ll,vector<ll> >mp;
ll pr[60];
int cnt[60],nw[60],ss;
int CNT;

void print(ll x){
    printf("%lld ",x);
    if((++CNT)==LIM) exit(0);
}

void tajzie(ll x){
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<ss;i++){
	while(x%pr[i]==0)
	    x/=pr[i],cnt[i]++;
    }
}

void go(vector<ll>&vec,ll zr=1,int id=0){
    if(id==ss){
	vec.PB(zr);
	return;
    }
    ll s=1;
    for(int i=0;i<=cnt[id];i++){
	go(vec,zr*s,id+1);
	s*=pr[id];
    }
}

void dfs(ll u,ll h){
    if(h==0 || u==1){
	print(u);
	return;
    }
    vector<ll>vec;
    if(mp.count(u)){
	vec=mp[u];
    }
    else{
	tajzie(u);
	go(vec);
	sort(vec.begin(),vec.end());
	mp[u]=vec;
    }
    for(ll x:vec){
	dfs(x,h-1);
    }
}

int main(){
    ll x,k;scanf("%lld%lld",&x,&k);
    ll X=x;
    for(ll p=2;(p*p)<=X;p++){
	if(X%p==0){
	    while(X%p==0)
		X/=p;
	    pr[ss++]=p;
	}
    }
    if(X>1)
	pr[ss++]=X;
    dfs(x,k);
}