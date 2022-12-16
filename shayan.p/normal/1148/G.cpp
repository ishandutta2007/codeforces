// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
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

const int maxn = 1e5 + 10, Max = 1e7 + 10;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

int a[maxn], b[maxn], c[maxn], L[maxn], R[maxn];
vector<int> dv[maxn], v[maxn];

int bigp[Max], val[Max];
int zr[maxn];

void add(vector<int> &vec){
    zr[0] = 1;
    val[1]++;
    for(int msk = 1; msk < (1<<sz(vec)); msk++)
	zr[msk] = zr[msk ^ (msk & -msk)] * vec[__builtin_ctz(msk)], val[ zr[msk] ]++;    
}
int ask(vector<int> &vec){
    zr[0] = 1;
    int ans = val[1];
    for(int msk = 1; msk < (1<<sz(vec)); msk++)
	zr[msk] = zr[msk ^ (msk & -msk)] * vec[__builtin_ctz(msk)], ans+= (__builtin_popcount(msk)&1 ? -1 : 1) * val[ zr[msk] ];
    return ans;
}
void go(int N){    
    for(int i = 0; i < N; i++){
	L[i] = 0, R[i] = N+1;
	dv[i].clear();
	int tmp = b[i];
	while(tmp > 1){
	    dv[i].PB( bigp[tmp] );
	    tmp/= bigp[tmp];
	}
    }
    while(true){
	vector<pii> vec;
	for(int i = 0; i < N; i++){
	    if(R[i] - L[i] > 1)
		vec.PB({ (R[i] + L[i]) >> 1, i });
	}
	if(sz(vec) == 0)
	    break;
	memset(val, 0, sizeof val);
	sort(vec.begin(), vec.end());
	int pt = 0;
	for(int i = 0; i < N; i++){
	    if(pt == sz(vec))
		break;
	    add(dv[i]);
	    while(pt < sz(vec) && vec[pt].F == i+1){
		if(ask(dv[ vec[pt].S ]) == 0)
		    L[ vec[pt].S ] = ( L[ vec[pt].S ] + R[ vec[pt].S ] ) >> 1;
		else
		    R[ vec[pt].S ] = ( L[ vec[pt].S ] + R[ vec[pt].S ] ) >> 1;
		pt++;
	    }
	}
    }
    for(int i = 0; i < N; i++){
	if(L[i] < N)
	    v[ c[i] ].PB( c[ L[i] ] ), v[ c[ L[i] ] ].PB( c[i] );
    }
}

bool mark[maxn];
int SZ[maxn];

vector<int> ids[maxn];
map<int, vector<int> > poses;

void dfs(int u){
    mark[u] = 1;
    SZ[u] = 1;
    for(int y : v[u])
	if(mark[y] == 0)
	    dfs(y), SZ[u]+= SZ[y];
}
void dfs2(int u, int &k, vector<int> &vans){
    while(k > 0 && sz(ids[u])){
	--k;
	vans.PB( ids[u].back() );
	ids[u].pop_back();
    }
    if(k == 0)
	return;
    mark[u] = 1;
    for(int y : v[u])
	if(mark[y] == 0)
	    dfs2(y, k, vans);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 2; i < Max; i++){
	if(bigp[i] == 0)
	    for(int j = i; j < Max; j+=i)
		bigp[j] = i;
    }
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
	cin >> a[i];
	int tmp = a[i];
	a[i] = 1;
	while(tmp > 1){
	    int P = bigp[tmp];
	    a[i]*= P;
	    while(tmp % P == 0)
		tmp/= P;
	}
	poses[ a[i] ].PB(i);
    }
    sort(a, a+n);
    n = unique(a, a+n) - a;
    for(int i = 0; i < n; i++){
	ids[i] = poses[ a[i] ];
    }

    for(int i = 0; i < n; i++){
	b[i] = a[i];
	c[i] = i;
    }
    int ID = -1;
    for(int i = 0; i < n; i++){
	if(b[i] == 1)
	    ID = i;
    }
    if(ID != -1){
	vector<int> ans;
	for(int x : ids[ID])
	    ans.PB(x);
	for(int i = 0; i < n; i++)
	    if(i != ID)
		for(int x : ids[i])
		    ans.PB(x);
	for(int i = 0; i < k; i++)
	    cout << ans[i]+1 << " ";
	return cout << endl, 0;
    }
    go(n);
    
    vector<int> vec;
    
    for(int i = 0; i < n; i++){
	if(mark[i] == 0 && (sz(v[i]) == 0 || sz(ids[ v[i].back() ]) <= sz( ids[i] ) ) )
	    dfs(i), vec.PB(i);
    }
    sort(vec.begin(), vec.end(), [&](int i, int j){ return SZ[i] < SZ[j]; } );
    int num = 0, num2 = 0;
    while(num < sz(vec) && SZ[ vec[num] ]  == 1)
	num2+= sz(ids[ vec[num] ]), num++;
    if(num2 >= k){
	vector<int> ans;
	for(int i = 0; i < num; i++)
	    for(int x : ids[ vec[i] ])
		ans.PB(x);
	for(int i = 0; i < k; i++)
	    cout << ans[i]+1 << " ";
	return cout << endl, 0;
    }
    for(int i = num; i < sz(vec); i++){
	b[i - num] = a[ vec[i] ];
	c[i - num] = vec[i];
    }
    if(SZ[ vec.back() ] == 2){
	go(sz(vec) - num);
	memset(mark, 0, sizeof mark);
	vec.clear();
	for(int i = 0; i < n; i++){
	    if(mark[i] == 0)
		dfs(i), vec.PB(i);		
	}
	sort(vec.begin(), vec.end(), [&](int i, int j){ return SZ[i] < SZ[j]; } );
    }
    if( SZ[ vec.back() ] == 2 ){
	vector<int> ans;
	for(int i = 0; i < sz(vec); i++)
	    for(int x : ids[ vec[i] ])
		ans.PB(x);
	for(int i = 0; i < k; i++)
	    cout << ans[i]+1 << " ";
	return cout << endl, 0;
    }
    memset(mark, 0, sizeof mark);
    
    int lst = -1;
    vector<int> vans;

    dfs2(vec.back(), k, vans);
    lst = vans.back();
    
    for(int i = sz(vec)-2; i >= 0; i--){
	if(k == 1){
	    vans.erase( find(vans.begin(), vans.end(), lst) );
	    vans.PB( ids[vec[i]][0] );
	    vans.PB( ids[ v[ vec[i] ].back() ][0] );
	    k = 0;
	}	
	dfs2(vec[i], k, vans);
    }
    for(int x : vans)
	cout << x + 1 << " ";
    return cout << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")