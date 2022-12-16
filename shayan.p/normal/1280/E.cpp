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

const int maxn = 2e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

int L[maxn], R[maxn], todo[maxn], dp[maxn], C;
vector<ll> ans;

void add(int l, int r, int t){
    L[C] = l, R[C] = r, todo[C] = t;
    if(t == 0)
	dp[C] = 1;
    if(t == 1)
	dp[C] = min( dp[l], dp[r] );
    if(t == 2)
	dp[C] = dp[l] + dp[r];
    C++;
}
void dfs(int u, ll x){
    if(todo[u] == 0){
	ans.PB(x);
	return;	
    }
    if(todo[u] == 1){
	if(dp[L[u]] < dp[R[u]])
	    dfs(L[u], x), dfs(R[u], 0);
	else
	    dfs(L[u], 0), dfs(R[u], x);	
    }
    if(todo[u] == 2){
	dfs(L[u], x);
	dfs(R[u], x);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
   
    int q;
    cin >> q;
    while(q--){
	int r;
	cin >> r;
	string s;
	getline(cin, s);
	C = 0;
	ans.clear();
	stack<int> st, st2;
	for(char ch : s){
	    if(ch == '*'){
		st.push(C);
		add(-1, -1, 0);
	    }
	    if(ch == '('){
		st.push(-1);
	    }
	    if(ch == 'S'){
		st2.push(1);
	    }
	    if(ch == 'P'){
		st2.push(2);
	    }
	    if(ch == ')'){
		int lst = st.top();
		st.pop();
		while(st.top() != -1){
		    add(st.top(), lst, st2.top());
		    st2.pop(), st.pop();
		    lst = C-1;///
		}
		st.pop();
		st.push(lst);
	    }
	};
	dfs(C-1, 1ll * r * dp[C-1]);
	cout << "REVOLTING ";
	for(ll x : ans)
	    cout << x << " ";
	cout << "\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")