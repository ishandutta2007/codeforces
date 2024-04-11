// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

struct Fenwick{
    vector<int>sm;
    int MX,tot;
    void build(int n){
	tot=0;
	MX=n+3;
	sm.resize(MX);
    }
    void add(int ind){
	tot++;
	while(ind<MX){
	    sm[ind]++;
	    ind+=(ind & -ind);
	}
    }
    int ask(int ind){
	if(ind>=MX)return tot;
	int ans=0;
	while(ind>0){
	    ans+=sm[ind];
	    ind-=(ind & -ind);
	}
	return ans;
    }
};

vector<int>dv[maxn];
Fenwick fen[maxn];
bool is[maxn];

int main(){
    for(int i=1;i<maxn;i++){
	fen[i].build(maxn/i);
    }
    for(int i=1;i<maxn;i++){
	for(int j=i;j<maxn;j+=i){
	    dv[j].PB(i);
	}
    }
    
    int q;scanf("%d",&q);
    while(q--){
	int task;scanf("%d",&task);
	if(task==1){
	    int x;scanf("%d",&x);
	    if(is[x])continue;
	    is[x]=1;
	    for(int d:dv[x])
		fen[d].add(x/d);
	}
	else{
	    int x,k,s;scanf("%d%d%d",&x,&k,&s);
	    if(x%k!=0 || (s-x)<k || fen[k].ask((s-x)/k)==0){
		printf("%d\n",-1);
		continue;
	    }
	    int l=1,r=(s-x)/k,nw=0;
	    for(int i=20;i>=0;i--){
		int lm=(nw+(1<<i)-1)/k;
		if(lm>r){
		    continue;
		}
		if(lm<l){
		    nw|=(1<<i);
		    continue;
		}
		int cn1=fen[k].ask(r)-fen[k].ask(lm);
		int cn0=fen[k].ask(lm)-fen[k].ask(l-1);
		if(bit(x,i)){
		    if(cn0>0)
			r=lm;
		    else
			nw|=(1<<i),l=lm+1;
		}
		else{
		    if(cn1>0)
			nw|=(1<<i),l=lm+1;
		    else
			r=lm;
		}
	    }
	    printf("%d\n",nw);
	}
    }
}