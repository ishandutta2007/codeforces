// only miss the sun when it starts to snow

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define left STRANGE_1
#define right STRANGE_2

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int n,k, ans[maxn];
vector<int> v[maxn];
vector<pii> qu[maxn];
vector<int> left[maxn], right[maxn];
int val[maxn];

int par[maxn];

int Find(int u){
    return par[u]<0 ? u : par[u]= Find(par[u]);
}
bool Merge(int a,int b){
    if( (a=Find(a)) == (b=Find(b)) ) return 0;
    if(par[a]>par[b]) swap(a,b);
    par[a]+=par[b];
    par[b]=a;
    return 1;
}

void solve(int l=0,int r=n){
    if(r-l==1){
	while(sz(qu[l])) ans[qu[l].back().S]=1, qu[l].pop_back();
	return;
    }
    int mid=(l+r)>>1;
    
    for(int i=l;i<r;i++)
	par[i]=-1, val[i]=0;

    for(int i=mid-1;i>=l;i--){
	int num=0;
	for(int j:v[i]){
	    if(i<=j && j<mid){
		num+= Merge(i,j);
	    }
	}
	val[i]= (i==mid-1 ? 0 : val[i+1]) + num;
	
	left[i].clear();
	for(int j=mid-1;j>=max(mid-1-k,i);j--){
	    left[i].PB(Find(j));
	}
    }
    for(int i=mid;i<r;i++){
	int num=0;
	for(int j:v[i]){
	    if(mid<=j && j<=i){
		num+=Merge(i,j);
	    }
	}
	val[i]= (i==mid ? 0 : val[i-1]) + num;
	
	right[i].clear();
	for(int j=mid;j<=min(mid+k, i);j++){
	    right[i].PB(Find(j));
	}
    }

    for(int i=l;i<r;i++)
	par[i]=-1;
    
    for(int L=l;L<mid;L++){
	while(!qu[L].empty() && qu[L].back().F>=mid){
	    int R=qu[L].back().F, id=qu[L].back().S;
	    qu[L].pop_back();

	    ans[id]= R-L+1 - val[L] - val[R];
	    
	    for(int i=max(mid-1-k,L);i<mid;i++){
		for(int j:v[i]){
		    if(mid<=j && j<=R)
			ans[id]-= Merge(left[L][mid-1-i],right[R][j-mid]);
		}
	    }
	    for(int i=max(mid-1-k,L);i<mid;i++){
		for(int j:v[i]){
		    if(mid<=j && j<=R)
			par[ left[L][mid-1-i] ]=-1 ,par[ right[R][j-mid] ]=-1;
		}
	    }
	}
    }
    
    solve(l,mid), solve(mid,r);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n>>k;
    int m; cin>>m;
    while(m--){
	int a,b; cin>>a>>b;
	v[--a].PB(--b);
	v[b].PB(a);
    }
    
    int q; cin>>q;
    for(int i=0;i<q;i++){
	int a,b; cin>>a>>b;
	qu[--a].PB({--b,i});
    }
    for(int i=0;i<n;i++){
	sort(qu[i].begin(), qu[i].end() );
    }

    solve(0,n);

    for(int i=0;i<q;i++){
	cout<<ans[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")