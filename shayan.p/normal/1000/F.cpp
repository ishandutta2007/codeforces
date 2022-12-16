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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const int maxn=5e5+10;
const int SQ=708;

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O1")
#pragma GCC Optimize("O2")
#pragma GCC Optimize("O3")
#pragma GCC Optimize("O4")
#pragma GCC Optimize("O5")


int lst[maxn];
vector< pair<pii,int> > val[4*maxn];
vector<int>mx[4*maxn];

pair<pii,int>a[maxn];
int n;

void Merge(vector<pair<pii,int> >&a,vector<pair<pii,int> >&b ,vector<pair<pii,int> >&c){
    int pb=0,pc=0;
    while((pb+pc)<(sz(b)+sz(c))){
	if(pb==sz(b))
	    a.PB(c[pc++]);
	else if(pc==sz(c))
	    a.PB(b[pb++]);
	else if(b[pb]<c[pc])
	    a.PB(b[pb++]);
	else
	    a.PB(c[pc++]);
    }
}

void build(int l=1,int r=n,int id=1){
    if(l==r){
	val[id].PB(a[l]);
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    Merge(val[id],val[2*id],val[2*id+1]);
    REP(i,sz(val[id])){
	mx[id].PB(max((mx[id].empty()?0:mx[id].back()),val[id][i].F.S));
    }
}

int ask_vec(int id,int f,int s){
    int l=0,r=sz(val[id])-1;
    while(l<r){
	int mid=(l+r)/2;
	if(val[id][mid].F.F<f && val[id][mid].F.S>s)return val[id][mid].S;
	if(val[id][mid].F.F>=f)
	    r=mid-1;
	else if(mx[id][mid]>s)
	    r=mid;
	else
	    l=mid+1;
    }
    if(val[id][l].F.F<f && val[id][l].F.S>s)return val[id][l].S;
    return 0;
}

int ask(int f,int s,int l=1,int r=n,int id=1){
    if(l>r || s<l || r<f)return 0;
    if(f<=l&&r<=s)return ask_vec(id,f,s);
    int mid=(l+r)/2;
    return max(ask(f,s,l,mid,2*id),ask(f,s,mid+1,r,2*id+1));
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
	scanf("%d",&a[i].S);
    }
    
    FOR(i,1,n){
	a[i].F.F=lst[a[i].S];
	lst[a[i].S]=i;
    }
    fill(lst,lst+maxn,n+1);
    FORD(i,n,1){
	a[i].F.S=lst[a[i].S];
	lst[a[i].S]=i;
    }
    
    build();
    
    int q;scanf("%d",&q);
    REP(i,q){
	int A,B;scanf("%d%d",&A,&B);
	printf("%d\n",ask(A,B));
    }
}