// And you curse yourself for things you never done

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, SQ = 330, SQ2 = (maxn / SQ) + 10;

int a[maxn];

int par[maxn], val[maxn];
int fnd(int u){
    return par[u] < 0 ? u : par[u] = fnd(par[u]);
}
void mrg(int a, int b){
    if( (a = fnd(a)) == (b = fnd(b)) )
	return;
    if(par[a] > par[b])
	swap(a, b);
    par[a]+= par[b];
    par[b] = a;
}

struct Block{
    int L, R;
    int LD, RD;
    int what[maxn];
    Block(){
	memset(what, -1, sizeof what);
    }
    void restart(){
	for(int i = L; i < R; i++){
	    a[i] = val[fnd(i)] - LD;
	}
	for(int i = L; i < R; i++){
	    what[val[i]] = -1;
	}
	for(int i = L; i < R; i++){
	    par[i] = -1;
	}
    }
    void build(){
	LD = 0, RD = 1;
	for(int i = L; i < R; i++){
	    val[i] = a[i];
	    RD = max(RD, a[i]);
	    if(what[a[i]] == -1)
		what[a[i]] = i;
	    mrg(what[a[i]], i);
	}	
    }
    void add(int x){
	if(LD + x >= RD)
	    return;
	int cnt1 = RD-LD-x, cnt2 = x;
	if(cnt1 <= cnt2){
	    for(int w = 0; w < cnt1; w++){
		if(what[RD-x] == -1)
		    what[RD-x] = what[RD];
		else if(what[RD] != -1)
		    mrg(what[RD], what[RD-x]);
		if(what[RD-x] != -1)
		    val[ fnd(what[RD-x]) ] = RD-x;
		what[RD] = -1;
		RD--;
	    }
	}
	else{
	    LD++;
	    for(int w = 0; w < cnt2; w++){
		if(what[LD+x] == -1)
		    what[LD+x] = what[LD];
		else if(what[LD] != -1)
		    mrg(what[LD], what[LD+x]);
		if(what[LD+x] != -1)
		    val[ fnd(what[LD+x]) ] = LD+x;		
		what[LD] = -1;
		LD++;
	    }
	    LD--;
	}
    }
    int ask(int x){
	if(x + LD > RD)
	    return 0;
	return what[LD+x] == -1 ? 0 : -par[ fnd(what[LD+x]) ];
    }
};Block block[SQ2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    memset(par, -1, sizeof par);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    for(int i = 0; i * SQ < n; i++){
	block[i].L = i * SQ;
	block[i].R = min(i * SQ + SQ, n);
	block[i].build();
    }
    while(q--){
	int task, l, r, x, ans = 0;
	cin >> task >> l >> r >> x;
	--l;

	int id = l / SQ;
	block[id].restart();	
	while(l < r && l % SQ){
	    if(task == 1)
		a[l]-= a[l] > x ? x : 0;
	    else
		ans+= a[l] == x;
	    l++;
	}
	block[id].build();	
	
	while(l + SQ <= r){
	    if(task == 1)
		block[l/SQ].add(x);
	    else
		ans+= block[l/SQ].ask(x);
	    l+= SQ;
	}
	if(l < r){
	    int id = l / SQ;
	    block[id].restart();	
	    while(l < r){
		if(task == 1)
		    a[l]-= a[l] > x ? x : 0;
		else
		    ans+= a[l] == x;
		l++;
	    }
	    block[id].build();	
	}
	if(task == 2){
	    cout << ans << "\n";
	}
    }
    return 0;
}