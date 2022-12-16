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

const int maxn = 3e5 + 10, mod = 1e9 + 7;
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

vector<int> v[maxn];

pii col[maxn];
vector<int> in[maxn][2];
bool is[maxn];

int ANS;

void add(int a, int c){
    int A = col[a].F;
    c^= col[a].S;
    if(is[A])
	return;
    is[A] = 1;
    if(c){
	for(int w = 0; w < 2; w++)
	    for(int x : in[A][w])
		col[x].S^=1;
	swap(in[A][0], in[A][1]);
	ANS-= sz(in[A][0]);
	ANS+= sz(in[A][1]);
    }
}
void add(int a, int b, int c){
    if(col[a].F == col[b].F)
	return;
    int A = col[a].F, B = col[b].F;
    c^= col[a].S ^ col[b].S;
    if(sz(in[A][0]) + sz(in[A][1]) < sz(in[B][0]) + sz(in[B][1]))
	swap(A, B);
    if(c && is[B] == 1){
	for(int w = 0; w < 2; w++)
	    for(int x : in[A][w])
		col[x].S^=1;
	swap(in[A][0], in[A][1]);
	ANS-= sz(in[A][0]);
	ANS+= sz(in[A][1]);
   }
    if(c && is[B] == 0){
	for(int w = 0; w < 2; w++)
	    for(int x : in[B][w])
		col[x].S^=1;
	swap(in[B][0], in[B][1]);
	ANS-= sz(in[B][0]);
	ANS+= sz(in[B][1]);
    }
    for(int w = 0; w < 2; w++)
	for(int x : in[B][w])
	    in[A][w].PB(x), col[x] = {A, w};
    in[B][0].clear(), in[B][1].clear();
    is[A] |= is[B];
    if(is[A] == 0 && sz(in[A][0]) < sz(in[A][1])){
	for(int w = 0; w < 2; w++)
	    for(int x : in[A][w])
		col[x].S^=1;
	swap(in[A][0], in[A][1]);
	ANS-= sz(in[A][0]);
	ANS+= sz(in[A][1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for(int i = 0; i < k; i++){
	col[i] = {i, 0};
	in[i][0].PB(i);
    }
    for(int i = 0; i < k; i++){
	int c;
	cin >> c;
	for(int j = 0; j < c; j++){
	    int x;
	    cin >> x;
	    v[--x].PB(i);
	}
    }
    for(int i = 0; i < n; i++){
	if(sz(v[i]) == 1){
	    add(v[i][0], s[i]=='0');
	}
	if(sz(v[i]) == 2){
	    add(v[i][0], v[i][1], s[i]=='0');	    
	}
	cout << ANS <<"\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")