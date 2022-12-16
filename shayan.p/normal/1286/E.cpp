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

const int maxn = 6e5 + 10, mod = 1e9 + 7, inf = 2e9;

struct node{
    node *nxt;
    int val;
    node(node* nxt, int val) : nxt(nxt), val(val){}
};
node* tdo[maxn];
int a[maxn], w[maxn], f[maxn], n;

map<int, int> mp;
ll sm;

void era(int x){
    sm-= x;
    assert(mp.count(x));
    if(--mp[x] == 0)
	mp.erase(x);
}
void add(int x){
    mp[x]++;
    sm+= x;
}
void minim(int x){
    while( sz(mp) && (mp.rbegin() -> F) > x ){
	pll p = *mp.rbegin();
	mp.erase(p.F);	
	sm-= 1ll * p.F * p.S;
	sm+= 1ll * x * p.S;
	mp[x]+= p.S;
    }
}
ll ask(){
    return sm;
}

const ll Base =1e15;

ll ans1, ans2;

void add(ll x){
    ans1 += x;
    ans2+= ans1/Base;
    ans1%=Base;
}
void print(){
    if(ans2 == 0){
	cout << ans1 <<"\n";
	return;
    }
    cout << ans2;
    ll tmp = ans1;
    string s;
    for(int i = 0; i < 15; i++)
	s = char('0' + (tmp % 10)) + s, tmp/=10;
    cout << s <<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
  
    tdo[0] = 0;
    
    cin >> n;

    vector<int> st;
    
    for(int i = 1; i <= n; i++){
	char ch; cin >> ch >> w[i];
	a[i]= ch - 'a';
	a[i] = ( 1ll * a[i] + ans1 + 1ll * Base %26 * ans2 ) % 26;
	w[i] ^= (ans1 + ans2 * Base) & ((1<<30)-1);
	
	vector<int> dl;
	
	f[i] = f[i-1];
	while(f[i] > 0 && a[ f[i] + 1 ] != a[i])
	    dl.PB(f[i]), f[i] = f[ f[i] ];
	f[i] += a[ f[i] + 1 ] == a[i];
	if(i == 1)
	    f[i] = 0;
	tdo[i] = tdo[f[i]];
	while(sz(dl)){
	    tdo[i] = new node(tdo[i], dl.back());
	    dl.pop_back();
	}

	node *tmp = tdo[i];
	while(tmp != 0){
	    era( w[ *lower_bound(st.begin(), st.end(), i - (tmp->val)) ] );
	    tmp = tmp->nxt;
	}
	if(a[i] == a[1]){
	    add(w[i]);
	}
	minim(w[i]);
	add(ask());
	print();

	while(sz(st) && w[ st.back() ] >= w[i])
	    st.pop_back();
	st.PB(i);

    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")