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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

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

int ans[maxn], n;

bool ask(vector<int> v){
    cout << "? " << sz(v) << " ";
    for(int x : v)
	cout << x+1 << " ";
    cout << endl;
    bool x;
    cin >> x;
    return x;
}
void print(){
    if(ans[0] >= (n/2))
	for(int i = 0; i < n; i++)
	    ans[i] = n-1-ans[i];
    cout << "! ";
    for(int i = 0; i < n; i++)
	cout << ans[i]+1 << " ";
    cout<<endl;
}

map< vector<int>, int > mp;
vector<int> rem[maxn];

pii go(int i){
    bool b = 0;
    pii p = {-1, -1};
    for(int j = 0; j < n; j++){
	if(ans[j] != -1)
	    continue;
	vector<int> v;
	for(int k = 0; k < n; k++)
	    if(ans[k] == -1 && k != j)
		v.PB(k);
	if(ask(v)){
	    if(b == 0)
		p.F = j;
	    else
		p.S = j;
	    b = 1;
	}		
    }
    ans[p.F] = i, ans[p.S] = n-1-i;
    return p;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    cin >> n;
    memset(ans, -1, sizeof ans);
    pii pp = go(0);
    for(int i = 0; i < n; i++){
	if(i != pp.F && i != pp.S)
	    rem[i].PB( !ask({i, pp.F}) );
    }
    for(int i = 1; i < min(4, n/2); i++){
	pii p = go(i);
	if(rem[p.F][0] != (i&1))
	    swap(ans[p.F], ans[p.S]);
    }
    if(n <= 8){
	print();
	return 0;
    }
    for(int i = 0; i < n; i++){
	mp[ {i%8, i%3, i%5, i%7} ] = i;
    }
    
    vector<pii> vals;    
    for(int i = 0; i < n; i++){
	if(ans[i] != -1)
	    vals.PB({ans[i], i});
    }

    auto fnd_vec = [&](int r, int md){
		       vector<int> v;
		       for(int msk = 0; msk < (1<<sz(vals)); msk++){
			   if(__builtin_popcount(msk) != md-1)
			       continue;
			   int num = 0;
			   for(int i = 0; i < sz(vals); i++)
			       if(bit(msk, i))
				   num+= vals[i].F;
			   if(num % md == r){
			       for(int i = 0; i < sz(vals); i++)
				   if(bit(msk, i))
				       v.PB(vals[i].S);
			       return v;
			   }
		       }
		       return v;
		   };
	
    for(int i = 0; i < n; i++){
	if(ans[i] != -1)
	    continue;
	int r = (4-rem[i][0]) %4;
	vector<int> v = fnd_vec(r, 4);
	bool change = 0;
	if(v.empty()){
	    v = fnd_vec((r + 2) %4, 4);
	    change = 1;
	}
	v.PB(i);
	rem[i][0]+= (ask(v) ^ change) ? 0 : 2;
    }
    for(int i = 0; i < n; i++){
	if(ans[i] != -1)
	    continue;
	int r = (8-rem[i][0]) %8;
	vector<int> v = fnd_vec(r, 8);
	bool change = 0;
	if(v.empty()){
	    v = fnd_vec((r + 4) %8, 8);
	    change = 1;
	}
	v.PB(i);
	rem[i][0]+= (ask(v) ^ change) ? 0 : 4;
    }
    for(int md : {3, 5, 7}){
	for(int i = 0; i < n; i++){
	    if(ans[i] != -1)
		continue;
	    for(int r = 0; r < md-1; r++){
		vector<int> v = fnd_vec(r, md);
		v.PB(i);
		if(ask(v)){
		    rem[i].PB((md-r) % md);
		    goto Hell;
		}
	    }
	    rem[i].PB(1);
	Hell:;
	}
    }
    for(int i = 0; i < n; i++){
	if(ans[i] == -1)
	    ans[i] = mp[rem[i]];
    }
    print();
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")