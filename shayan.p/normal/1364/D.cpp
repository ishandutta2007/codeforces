// Never let them see you bleed...
// Shayan.P  2020-06-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<int> v[maxn];
bool mark[maxn], bad[maxn];
int h[maxn], pr[maxn];
int k;

void tell1(vector<int> vec){
    cout << 1 << "\n";
    for(int i = 0; i < (k+1)/2; i++)
	cout << vec[i] << " ";
    cout << endl;
    exit(0);
}
void tell2(vector<int> vec){
    cout << 2 << "\n" << sz(vec) << "\n";
    for(int x : vec)
	cout << x << " ";
    cout << endl;
    exit(0);
}

void dfs(int u, int par = 0){
    mark[u] = 1;
    h[u] = h[par] + 1;
    pr[u] = par;
    for(int y : v[u]){
	if(mark[y] == 0){
	    dfs(y, u);
	}
	else if(y != par && h[u] > h[y]){
	    bad[y] = 1;
	    if(h[u] - h[y] + 1 <= k){
		vector<int> vec;
		int tmp = u;
		while(tmp != y)
		    vec.PB(tmp), tmp = pr[tmp];
		vec.PB(y);
		tell2(vec);
	    }
	}
    }
}

vector<int> vec1, vec2;

void dfs2(int u, int h = 0){
    if(h & 1)
	vec1.PB(u);
    else
	vec2.PB(u);
    bad[u] = 1;
    for(int y : v[u]){
	if(bad[y] == 0)
	    dfs2(y, h+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
	if(bad[i] == 0)
	    dfs2(i);
    }
    if(sz(vec1) < sz(vec2))
	tell1(vec2);
    tell1(vec1);
    return 0;
}