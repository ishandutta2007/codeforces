// Never let them see you bleed...
// Shayan.P  2020-06-25

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10, Big = 1e7;

int mn[4 * maxn], mn2[4 * maxn], lz[4 * maxn];

void shift(int l, int r, int id){
    mn[id]+= lz[id];
    mn2[id]+= lz[id];
    if(r-l > 1){
	lz[2*id]+= lz[id];
	lz[2*id+1]+= lz[id];	
    }
    lz[id] = 0;
}
int fnd0(int pos, int l = 0, int r = maxn, int id = 1){
    shift(l, r, id);
    if(r <= pos || mn[id] != 0)
	return -1;
    if(r-l == 1)
	return l;
    int mid = (l+r) >> 1;    
    int num = fnd0(pos, l, mid, 2*id);
    if(num == -1)
	return fnd0(pos, mid, r, 2*id+1);
    return num;	
}
int fnd1(int pos, int l = 0, int r = maxn, int id = 1){
    shift(l, r, id);
    if(r <= pos || (mn[id] != 1 && mn2[id] != 1))
	return -1;
    if(r-l == 1)
	return l;
    int mid = (l+r) >> 1;
    int num = fnd1(pos, l, mid, 2*id);
    if(num == -1)
	return fnd1(pos, mid, r, 2*id+1);
    return num;
}
void sum(int f, int s, int x, int l = 0, int r = maxn, int id = 1){    
    if(f >= s || l >= r)
	return;
    shift(l, r, id);
    if(s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	lz[id] = x;
	shift(l, r, id);
	return;
    }
    int mid = (l+r) >> 1;
    sum(f, s, x, l, mid, 2*id);
    sum(f, s, x, mid, r, 2*id+1);

    mn[id] = min(mn[2*id], mn[2*id+1]);
    mn2[id] = min(mn2[2*id], mn2[2*id+1]);
    if(mn[id] != mn[2*id])
	mn2[id] = min(mn2[id], mn[2*id]);
    if(mn[id] != mn[2*id+1])
	mn2[id] = min(mn2[id], mn[2*id+1]);
}
void add(int pos){
    sum(pos, fnd0(pos) + 1, 1);
}
void era(int pos){
    sum(pos, fnd1(pos) + 1, -1);
}
int ask(int l = 0, int r = maxn, int id = 1){
    shift(l, r, id);
    if(r-l == 1)
	return l;
    int mid = (l+r) >> 1;
    if(mn[2*id+1] + lz[2*id+1] == 0 && mn2[2*id+1] + lz[2*id+1] > Big)
	return ask(l, mid, 2*id);
    else
	return ask(mid, r, 2*id+1);	
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fill(mn2, mn2 + 4 * maxn, inf);
    
    int n, k, q;
    cin >> n >> k >> q;
    set<pii> st;
    while(q--){
	int x, y;
	cin >> x >> y;
	bool ad = 1;
	if(st.count({x, y}))
	    st.erase({x, y}), ad = 0;
	else
	    st.insert({x, y});
	y+= abs(x-k);
	if(ad)
	    add(y-1);
	else
	    era(y-1);
	cout << max(int(0), ask()+1-n) << "\n";
    }
    return 0;
}