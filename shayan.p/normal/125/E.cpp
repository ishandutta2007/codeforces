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
typedef pair<pii,pii> pi4;

const int maxn = 1e5 + 10, mod = 1e9 + 7, Big = 1e6 + 10;

vector<pi4> vec;
bool is[maxn];

int par[maxn];

int fnd(int u){
    return (par[u]<0 ? u : par[u] = fnd(par[u]) );
}
bool mrg(int a, int b){
    if( (a = fnd(a)) == (b = fnd(b)) )
	return 0;
    if( par[a] > par[b] )
	swap(a, b);
    par[a]+= par[b];
    par[b] = a;
    return 1;
}
void mst(int mid){    
    sort(vec.begin(), vec.end(), [&](pi4 a, pi4 b){
    	    bool aa = a.S.F == 1 || a.S.S == 1, bb = b.S.F == 1 || b.S.S == 1;
    	    int A = a.F.F + (aa ? mid : 0), B = b.F.F + (bb ? mid : 0);
    	    return (pii){A, aa^1} < (pii){B, bb^1};
    	});
    memset(par, -1, sizeof par);
    for(auto x : vec)
	is[x.F.S] = mrg(x.S.F, x.S.S);
}
int calc(int k){
    int l = -Big, r = Big;
    
    while(r-l>1){
	int mid = (l+r)/2;
	
	mst(mid);
	
	int cnt = 0;
	for(auto x : vec)
	    cnt+= (is[x.F.S] && (x.S.F == 1 || x.S.S == 1));
	if(cnt == k)
	    return mid;
	if(cnt > k)
	    l = mid;
	else
	    r = mid;
    }
    if(r == Big || l == -Big)
	l = -Big;
    return l;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m,k;
    cin >> n >> m >> k;

    for(int i=0; i<m; i++){
	int a,b,w;
	cin >> a >> b >> w;
	vec.PB({ {w,i} , {a,b} });
    }
    int num = calc(k);
    
    mst(num);

    int cnt = 0;
    for(int i=0; i<m; i++)
	cnt+= is[i];
    if(num == -Big || cnt != n-1)
	return cout << -1 << endl, 0;
    
    memset(par, -1, sizeof par);
    for(auto x : vec){
	if(k == 0 && ( x.S.F == 1 || x.S.S == 1 ) ){
	    is[ x.F.S ] = 0;
	    continue;
	}
	is[ x.F.S ] = mrg( x.S.F, x.S.S );
	if( x.S.F == 1 || x.S.S == 1 )
	    k-= is[ x.F.S ];
    }
    cout<<n-1<<"\n";
    for(int i=0; i<m; i++){
	if(is[i])
	    cout<<i+1<<" ";
    }    
    return cout<<endl,0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")