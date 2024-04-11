// Oh my lord I need you by my side...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 10, mod = 998244353;

int a[maxn], b[maxn], val[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
	    int x;
	    cin >> x;
	    a[x] = i;
	}
	fill(val, val + n + 1, 0);
	val[0] = val[n+1] = n + 10;
	for(int i = 1; i <= k; i++){
	    int x;
	    cin >> x;
	    b[i] = a[x];
	    val[a[x]] = i;
	}
	
	set<int> st;
	for(int i = 0; i <= n+1; i++){
	    st.insert(i);
	}
	
	int ans = 1;
	for(int i = 1; i <= k; i++){
	    auto it = st.find(b[i]);
	    int X = val[*prev(it)], Y = val[*next(it)];
	    ans = 1ll * ans * ( (X < i) + (Y < i) ) % mod;
	}
	cout << ans << "\n";
    }    
    return 0;
}