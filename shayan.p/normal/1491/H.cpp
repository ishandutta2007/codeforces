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

const int maxn = 1e5 + 10, SQT = 330, SQC = (maxn / SQT) + 10;

int a[maxn], dp[maxn], lz[SQC], n;

set<int> smalls;
bool is_small[maxn];
int next_small[maxn];

void init_smalls(){
    for(auto it = smalls.begin(); it != smalls.end(); it++){
	next_small[*it] = next(it) == smalls.end() ? maxn : *next(it);
    }
}
void erase_small(int id){
    auto it = smalls.find(id);
    assert(it != smalls.end());
    int bef = it == smalls.begin() ? -1 : *prev(it);
    smalls.erase(it);
    is_small[id] = 0;
    if(bef != -1)
	next_small[bef] = next_small[id];
}

inline int small_jump(int id, int block_id){
    return max(int(0), a[id] - lz[block_id]);
}
inline int big_jump(int id, int block_id){
    return is_small[id] ? dp[id] : max(int(0), a[id] - lz[block_id]);
}

void relax(int block_id){
    int l = block_id * SQT, r = min(n, l + SQT);
    for(int i = l; i < r; i++){
	a[i] = max(int(0), a[i] - lz[block_id]);
	if(a[i] < l){
	    dp[i] = a[i];
	    if(is_small[i])
		erase_small(i);
	}
	else{
	    dp[i] = dp[a[i]];
	}
    }
    lz[block_id] = 0;
}
    
void add(int l, int r, int x){
    if(l < r){
	int id = l / SQT;
	while(l < r && l % SQT)
	    a[l++]-= x;
	relax(id);
    }
    if(l < r){
	int id = r / SQT;
	while(l < r && r % SQT)
	    a[--r]-= x;
	relax(id);
    }
    for(int i = l, id = l / SQT; i < r; i+= SQT, id++){
	lz[id]+= x;
	lz[id] = min(lz[id], maxn);
    }
    int tmp = maxn;
    auto it = smalls.lower_bound(l);
    if(it != smalls.end() && (*it) < r)
	tmp = *it;

    while(tmp < r){
	int id = tmp / SQT;
	int val = a[tmp] - lz[id];
	int nxt = next_small[tmp];
	if(val < id * SQT)
	    erase_small(tmp);
	else
	    dp[tmp] = big_jump(val, id);
	tmp = nxt;
    }
}
int lca(int a, int b){
    if(a == b)
	return a;
    while(true){
	if(a < b)
	    swap(a, b);
	int id_a = a / SQT, id_b = b / SQT;
	if(id_a != id_b)	    
	    a = big_jump(a, id_a);
	else{
	    int up_a = big_jump(a, id_a);
	    int up_b = big_jump(b, id_b);
	    if(up_a == up_b)
		break;
	    a = up_a;
	    b = up_b;
	}	    
    }
    int sq_id = a / SQT;
    while(a != b){
	if(a < b)
	    swap(a, b);
	a = small_jump(a, sq_id);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
	cin >> a[i];
	--a[i];
    }
    for(int i = 1; i < n; i++){
	int id = i / SQT, id2 = a[i] / SQT;
	if(id != id2){
	    dp[i] = a[i];
	}
	else{
	    dp[i] = dp[a[i]];
	    is_small[i] = 1;
	    smalls.insert(i);
	}
    }
    init_smalls();

    while(q--){
	int t;
	cin >> t;
	if(t == 1){
	    int l, r, x;
	    cin >> l >> r >> x;
	    add(--l, r, x);
	}
	else{
	    int a, b;
	    cin >> a >> b;
	    cout << lca(--a, --b) + 1 << "\n";
	}
    }
    return 0;
}