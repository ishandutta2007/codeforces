//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
 
ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


const int N = 200002;
int n, s, trie[N*30][2], cnt[N*30], par[N], sz[N], arr[N], ends_here[30*N];
set<int> distinct_;
vector<int> members[N];


int root(int v){
	if(v == par[v])	return v;
	return par[v] = root(par[v]);
}

void unite(int a, int b){
	a = root(a), b = root(b);
	if(a == b)	return;
	if(sz[a] < sz[b])	swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}


void insert(int n){
	int curr = 0;
	for(int i=29;i>=0;i--){
		int dir = (arr[n] >> i) & 1;
		if(trie[curr][dir] == -1)	trie[curr][dir] = ++s;
		curr = trie[curr][dir];
		cnt[curr]++;
	}
	ends_here[curr] = n;
}


void remove(int n){
	int curr = 0;
	for(int i=29;i>=0;i--){
		int dir = (arr[n] >> i) & 1;
		curr = trie[curr][dir];
		cnt[curr]--;
	}
}


ii query(int n){
	int curr = 0;
	ii ans (0, 0);
	for(int i=29;i>=0;i--){
		int dir = (arr[n] >> i) & 1;
		if(cnt[trie[curr][dir]] > 0){
			curr = trie[curr][dir];
		}
		else{
			ans.ff += (1<<i);
			curr = trie[curr][1^dir];
		}
	}
	ans.ss = ends_here[curr];
	return ans;
}


 
int main(){

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    scanf("%d", &n);
    for(int i=1;i<=n;i++){
    	scanf("%d", &arr[i]);
    	distinct_.insert(arr[i]);
    }

    n = 0;
    s = 0;
    memset(trie, -1, sizeof(trie));
    
    for(auto it : distinct_){
    	arr[++n] = it;
    	insert(n);
    	par[n] = n;
    	sz[n] = 1;
    }


    int comp = n;
    ll ans = 0;
    while(comp > 1){

// cout<<"now at: "<<"comp = "<<comp<<", ans = "<<ans<<endl;
// cout<<"root: ";for(int i=1;i<=n;i++)	cout<<root(i)<<" ";cout<<endl;
// cout<<endl;

    	for(int i=1;i<=n;i++){
    		members[i].clear();
    	}

    	for(int i=1;i<=n;i++){
    		members[root(i)].pb(i);
    	}

    	set<iii> selected_edges;
    	for(int i=1;i<=n;i++){
    		
    		if(members[i].empty())	continue;
    		for(auto it : members[i]){
    			remove(it);
    		}

    		ii min_out (MOD, MOD);
    		for(auto it : members[i]){
    			ii temp = query(it);
    			min_out = min(min_out, temp);
    		}

    		int a = min(root(min_out.ss), i), b = max(root(min_out.ss), i);
    		selected_edges.insert({{a, b}, min_out.ff});

    		for(auto it : members[i]){
    			insert(it);
    		}
    	}

// cout<<"selected_edges: ";for(auto it : selected_edges)	cout<<it.ff.ff<<":"<<it.ff.ss<<":"<<it.ss<<" ";cout<<endl;

    	for(auto it : selected_edges){
    		ans += it.ss;
    		unite(it.ff.ff, it.ff.ss);
    		comp--;
    	}
    }

    printf("%I64d\n", ans);
    return 0;
}