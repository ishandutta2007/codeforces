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

const int maxn = 33, Max = 2e5 + 10;

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

string s[maxn];
int start[maxn], who[Max];
int mark[Max];
bool is[maxn];
vector<pii> v[Max];

bool dfs(int u){
    mark[u] = 1;
    for(auto [y, id] : v[u]){
	if((y == 0 || is[who[y]]) && is[id]){
	    if(mark[y] == 1)
		return 1;
	    if(mark[y] == 0)
		if(dfs(y))
		    return 1;
	}
    }
    mark[u] = 2;
    return 0;
}
bool cyc(){
    memset(mark, 0, sizeof mark);
    for(int i = 0; i < Max; i++){
	if((i == 0 || is[who[i]]) && mark[i] == 0)
	    if(dfs(i))
		return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n;
    cin >> n;

    start[0] = 1;    
    for(int i = 0; i < n; i++){
	cin >> s[i];	
	start[i+1] = start[i] + sz(s[i]);
	for(int j = start[i]; j < start[i+1]; j++)
	    who[2 * j] = who[2 * j + 1] = i;
    }
    for(int i = 0; i < n; i++){
	for(int j = i+1; j < n; j++){
	    int SZ = min(sz(s[i]), sz(s[j]));
	    if(s[i].substr(0, SZ) == s[j].substr(0, SZ) && sz(s[i]) != sz(s[j])){
		if(sz(s[i]) == SZ)
		    v[0].PB({2*(start[j] + SZ), i}), v[0].PB({2*(start[j] + SZ) + 1, i});
		else
		    v[0].PB({2*(start[i] + SZ), j}), v[0].PB({2*(start[i] + SZ) + 1, j});
	    }
	}
    }
    for(int i = 0; i < n; i++){
	for(int j = 0; j < sz(s[i]); j++){
	    for(int k = 0; k < n; k++){
		int SIZE = min(sz(s[i]) - j, sz(s[k]));
		if(s[i].substr(j, SIZE) == s[k].substr(0, SIZE)){
		    if(sz(s[i]) - j == sz(s[k])){
			v[2 * (start[i] + j)].PB({0, k});
			v[2 * (start[i] + j)+1].PB({0, k});
		    }
		    else if(SIZE == sz(s[i]) - j){
			v[2 * (start[i] + j)].PB({2 * (start[k] + SIZE) + 1, k});
			v[2 * (start[i] + j)+1].PB({2 * (start[k] + SIZE), k});
		    }
		    else{
			v[2 * (start[i] + j)].PB({2 * (start[i] + j + SIZE), k});
			v[2 * (start[i] + j)+1].PB({2 * (start[i] + j + SIZE)+1, k});
		    }
		}		    
	    }
	}
    }

    int r = 0, ans = 0;
    for(int i = 0; i < n; i++){
	r = max(r, i);
	while(r < n){
	    is[r] = 1;
	    if(cyc()){
		is[r] = 0;
		break;
	    }
	    r++;
	}
	ans+= r-i;
	is[i] = 0;
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")