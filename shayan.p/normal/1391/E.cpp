// And you curse yourself for things you never done
// Shayan.P  2020-08-09

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<int> v[maxn];
set<int> lfs;
int pr[maxn], chld[maxn];
int C, st[maxn], rst[maxn];
bool mark[maxn];

void dfs(int u){
    st[u] = C;
    rst[C] = u;
    C++;
    mark[u] = 1;
    for(int y : v[u]){
	if(mark[y] == 0){
	    pr[y] = u;
	    chld[u]++;
	    dfs(y);
	}
    }
}
void go(int u, vector<int> &vec){
    vec.PB(u);
    mark[u] = 1;
    int cnt = 0;
    for(int y : v[u]){
	if(mark[y] == 0)
	    go(y, vec), cnt++;
    }
    assert(cnt <= 1);
} 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
	    v[i].clear();
	}	
	C = 0;
	lfs.clear();
	fill(mark + 1, mark + n + 1, 0);
	fill(chld + 1, chld + n + 1, 0);
	
	for(int i = 0; i < m; i++){
	    int a, b;
	    cin >> a >> b;
	    v[a].PB(b);
	    v[b].PB(a);
	}	
	dfs(1);
	fill(mark + 1, mark + n + 1, 0);
	
	for(int i = 1; i <= n; i++){
	    if(chld[i] == 0)
		lfs.insert(st[i]);
	}
	auto era = [&](int u){
		       mark[u] = 1;
		       lfs.erase(st[u]);		       
		       if(--chld[pr[u]] == 0)
			   lfs.insert(st[pr[u]]);
		   };
	vector<pii> prs;
	while(sz(lfs) > 1){
	    int A = *lfs.begin(), B = *lfs.rbegin();
	    era(rst[A]), era(rst[B]);
	    prs.PB({rst[A], rst[B]});
	}	
	if(sz(prs) * 2 * 2 >= n){
	    cout << "PAIRING\n";
	    cout << sz(prs) << "\n";
	    for(pii p : prs)
		cout << p.F << " " << p.S << "\n";
	}
	else{
	    vector<int> pt;
	    go(1, pt);
	    cout << "PATH\n";
	    cout << sz(pt) << "\n";
	    for(int x : pt)
		cout << x << " ";
	    cout << "\n";
	}
    }
    return 0;
}