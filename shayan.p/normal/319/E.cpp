// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10;
const ll TW=262144;

map<ll,ll>mp;
pll seg[maxn];
ll par[maxn];
ll t[maxn],a[maxn],b[maxn];
ll LL,RR;

ll Find(ll u){
    return (par[u]<0?u:(par[u]=Find(par[u])));
}
void Merge(ll a,ll b){
    if((a=Find(a))==(b=Find(b))) return;
    if(par[a]>par[b])swap(a,b);
    par[a]+=par[b];
    par[b]=a;
}

ll mx[2*TW+10];
priority_queue<pll>pq[TW+10];

bool ERASE(ll s,ll x,ll ind){
    s+=TW+1;
    ll f=TW,here=-1;
    while(f<s){
	if(s%2){
	    if(mx[--s]>x){
		here=s;
		break;
	    }
	}
	f/=2;s/=2;
    }
    if(here==-1)return 0;
    while(here<TW){
	if(mx[2*here+1]>x)
	    here=2*here+1;
	else
	    here=2*here;
    }
    
    here-=TW;
    LL=min(LL,here);
    while(sz(pq[here])){
	pll p=pq[here].top();
	if(p.F<=x) break;
	RR=max(RR,p.F);
	Merge(ind,p.S);
	pq[here].pop();
    }
    ll lst=((pq[here].empty())?(0):(pq[here].top().F));
    here+=TW;
    mx[here]=lst;
    here/=2;
    while(here>0){
	mx[here]=max(mx[2*here],mx[2*here+1]);
	here/=2;
    }
    return 1;
}

void ADD(ll l,ll r,ll ind){
    pq[l].push(MP(r,ind));
    l+=TW;
    while(l>0){
	mx[l]=max(mx[l],r);
	l/=2;
    }
}

int main(){
    fill(par,par+maxn,-1);
    ll q;cin>>q;
    REP(i,q){
	cin>>t[i]>>a[i]>>b[i];
	if(t[i]==1){
	    mp[a[i]]=mp[b[i]]=0;
	}
    }
    ll h=2;// ke tooye erase be -1 bar nakhorim
    for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++){
	mp[it->F]=(h++);
    }
    
    h=0;
    REP(i,q){
	if(t[i]==1){
	    LL=a[i]=mp[a[i]];
	    RR=b[i]=mp[b[i]];
	    while(ERASE(a[i]-1,a[i],h)){
	    }
	    while(ERASE(b[i]-1,b[i],h)){
	    }
	    seg[Find(h)]=MP(LL,RR);
	    ADD(LL,RR,Find(h));
	    h++;
	}
	else{
	    pll p1=seg[Find(a[i]-1)],p2=seg[Find(b[i]-1)];
	    cout<<((p2.F<=p1.F&&p1.S<=p2.S)?"YES\n":"NO\n");
	}
    }
}