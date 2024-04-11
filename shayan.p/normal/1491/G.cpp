// better, faster, stronger
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 10;

int A[maxn], AR[maxn];
bool col[maxn];
bool mark[maxn];

vector<pii> ans;

void SW(int a, int b){
    assert(a != b);
    ans.PB({a, b});
    swap(A[a], A[b]);
    swap(col[a], col[b]);
    col[a]^= 1, col[b]^= 1;
}
pii len(int s){
    mark[s] = 1;
    int tmp = A[s];
    int n = 1, bl = col[s];
    while(tmp != s){
	mark[tmp] = 1;
	n++;
	bl+= col[tmp];
	tmp = A[tmp];
    }
    return {n, bl};
}
int reduce_one_black_cyc(int s){
    auto [n, bl] = len(s);
    assert(bl == 1);
    while(!col[s])
	s = A[s];
    while(n > 2){
	while(col[A[s]])
	    s = A[s];
	n--;
	SW(s, A[s]);
    }
    return s; // the black one
}
void solve_even_black_cyc(int s){
    auto [n, bl] = len(s);
    assert(bl % 2 == 0);
    assert(bl);
    while(!col[s])
	s = A[s];
    while(n > bl){
	while(col[A[s]])
	    s = A[s];
	n--;
	SW(s, A[s]);
    }
    vector<int> vvv;
    int tmp = A[s];
    while(tmp != s){
	vvv.PB(tmp);
	tmp = A[tmp];
    }
    vvv.PB(tmp);
    reverse(vvv.begin(), vvv.end());
    assert(sz(vvv) == bl);
    for(int i = 0; i < sz(vvv)-1; i++){
	SW(vvv[i], vvv[i+1]);
    }
}
void solve_cyc(int s){
    auto [n, bl] = len(s);
    if(n == 1)
	return;
    assert(n >= 3);
    if(n == 3){	
	int b = A[s], c = A[b];
	SW(s, b);
	SW(b, c);
	s = c;
	
	b = A[s];
	c = A[b];
	SW(s, c);
	SW(b, c);
    }
    else{
	int b1 = A[A[s]];
	SW(s, b1);
	int b2 = reduce_one_black_cyc(s);
	SW(A[b1], A[b2]);
	solve_even_black_cyc(b1);
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
	cin >> A[i];
    }
    vector<pii> cyc;
    for(int i = 1; i <= n; i++){
	if(!mark[i])
	    cyc.PB({len(i).F, i});
    }
    sort(cyc.begin(), cyc.end());
    reverse(cyc.begin(), cyc.end());
    if(cyc[0].F == 1){
	return cout << 0 << endl, 0;
    }
    while(sz(cyc)){
	if(cyc.back().F == 1 && n-1 >= 3){
	    n--;
	    cyc.pop_back();
	    continue;
	}
	int cnt = sz(cyc);
	if(cnt == 1)
	    break;
	if((n - cyc[cnt-1].F - cyc[cnt-2].F >= 3) || sz(cyc) == 2){
	    n-= cyc[cnt-1].F + cyc[cnt-2].F;
	    SW(cyc[cnt-1].S, cyc[cnt-2].S);
	    solve_even_black_cyc(cyc[cnt-1].S);
	    cyc.pop_back();
	    cyc.pop_back();
	    continue;
	}
	break;
    }
    if(sz(cyc)){
	if(sz(cyc) == 1){
	    solve_cyc(cyc[0].S);
	}
	else{
	    assert(sz(cyc) == 3 && cyc[0].F == 2 && cyc[2].F == 2);
	    int a = cyc[0].S, b = cyc[1].S, c = cyc[2].S;
	    int bb = A[b];
	    SW(a, b);
	    SW(bb, c);
	    solve_even_black_cyc(a);
	}
    }
    cout << sz(ans) << "\n";
    for(pii p : ans){
	cout << p.F << " " << p.S << "\n";
    }
}