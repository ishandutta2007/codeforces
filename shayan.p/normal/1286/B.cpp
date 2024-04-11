// They can't break me, as long as I know who I am...

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

const int maxn = 2010, mod = 1e9 + 7;
const ll inf = 1e18;

int a[maxn], ans[maxn];
vector<int> v[maxn];

int cnt[maxn], n;

int get(int k){
    int pos = 1;
    while(pos <= n && k > 0){
	k-= cnt[pos];
	pos++;	
    }
    if(pos > n && k > 0)
	cout << "NO\n", exit(0);
    return pos-1;
}
int ask(int k){
    int sm = 0;
    for(int i = 1; i<=k; i++)
	sm+= cnt[i];
    return sm;
}

void dfs(int u){
    ans[u] = get(a[u]+1);
    cnt[ ans[u] ] = 0;
    for(int y : v[u])
	dfs(y);
}
void chk(int u){
    cnt[ ans[u] ] = 1;
    int num = ask( ans[u] );
    for(int y : v[u])
	chk(y);
    if(ask( ans[u] ) - num != a[u])
	cout << "NO\n", exit(0);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n;
    int rt= -1;
    for(int i = 1; i <= n; i++){
	cnt[i] = 1;
	
	int x; cin>>x>>a[i];
	v[x].PB(i);
	if(x == 0)
	    rt = i;
    }
    dfs(rt);
    chk(rt);
    cout<<"YES\n";
    for(int i = 1; i<=n; i++)
	cout<<ans[i]<<" ";
	    return cout<<endl,0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")