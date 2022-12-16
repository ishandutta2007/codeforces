// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-06

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 5e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

bool lz[4 * maxn];
int suf[4 * maxn][2], pre[4 * maxn][2], pre2[4 * maxn][2], suf2[4 * maxn][2], tot[4 * maxn][2], LN[4 * maxn];
string s;
int n;

void mrg(int id, int id1, int id2){
    for(int o : {0, 1}){
	pre[id][o] = (pre[id1][o] == LN[id1] ? LN[id1] + pre[id2][o] : pre[id1][o]);
	suf[id][o] = (suf[id2][o] == LN[id2] ? LN[id2] + suf[id1][o] : suf[id2][o]);
    }
    for(int o : {0, 1}){
	pre2[id][o] = max({ pre2[id1][o], pre[id1][o^1] == LN[id1] ? LN[id1] + pre2[id2][o] : 0, pre[id][o], tot[id1][o] == LN[id1] ? LN[id1] + pre[id2][o] : 0 });
	suf2[id][o] = max({ suf2[id2][o], suf[id2][o^1] == LN[id2] ? LN[id2] + suf2[id1][o] : 0, suf[id][o], tot[id2][o] == LN[id2] ? LN[id2] + suf[id1][o] : 0 });
    }
    for(int o : {0, 1}){
	suf2[id][o] = max({suf2[id][o], suf[id][o], suf[id][o^1]});
	tot[id][o] = max({tot[id1][o], tot[id2][o], suf[id1][o] + pre2[id2][o], suf2[id1][o] + pre[id2][o]});
    }
}
void build(int l = 0, int r = n, int id = 1){
    if(r-l == 1){
	suf2[id][0] = suf2[id][1] = pre2[id][0] = pre2[id][1] = tot[id][0] = tot[id][1] = 1;
	if(s[l] == '<'){
	    pre[id][0] = 1;
	    suf[id][1] = 1;
	}
	else{
	    pre[id][1] = 1;
	    suf[id][0] = 1;
	}
	LN[id] = 1;
	return;	
    }
    int mid = (l+r) >> 1;
    build(l, mid, 2*id);
    build(mid, r, 2*id+1);
    mrg(id, 2*id, 2*id+1);
    LN[id] = LN[2 * id] + LN[2 * id + 1];
}
void shift(int l, int r, int id){
    if(lz[id] == 0)
	return;
    lz[id] = 0;
    swap(suf[id][0], suf[id][1]);
    swap(pre[id][0], pre[id][1]);
    swap(suf2[id][0], suf2[id][1]);
    swap(pre2[id][0], pre2[id][1]);
    swap(tot[id][0], tot[id][1]);
    if(r-l > 1){
	lz[2*id]^=1;
	lz[2*id+1]^=1;
    }	
}
void add(int f, int s, int l = 0, int r = n, int id = 1){
    if(f >= s || l >= r)
	return;
    shift(l, r, id);
    if(s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	lz[id] = 1;
	shift(l, r, id);
	int A = 4 * maxn - 2, B = 4 * maxn - 1;
	mrg(A, B, id);
	suf[B][0] = suf[A][0];
	suf[B][1] = suf[A][1];
	suf2[B][0] = suf2[A][0];
	suf2[B][1] = suf2[A][1];
	pre[B][0] = pre[A][0];
	pre[B][1] = pre[A][1];
	pre2[B][0] = pre2[A][0];
	pre2[B][1] = pre2[A][1];
	tot[B][0] = tot[A][0];
	tot[B][1] = tot[A][1];
	LN[B]+= LN[id];
	return;
    }
    int mid = (l+r) >> 1;
    add(f, s, l, mid, 2*id);
    add(f, s, mid, r, 2*id+1);
    mrg(id, 2*id, 2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> n >> q;
    cin >> s;
    build();
    while(q--){
	int l, r;
	cin >> l >> r;
	--l;
	int A = 4 * maxn - 1;
	suf[A][0] = suf[A][1] = suf2[A][0] = suf2[A][1] = pre[A][0] = pre[A][1] = pre2[A][0] = pre2[A][1] = tot[A][0] = tot[A][1] = LN[A] = 0; 
	add(l, r);
	cout << tot[A][0] << "\n";
    }
    return 0;
}