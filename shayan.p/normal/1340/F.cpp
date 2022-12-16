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

const int maxn = 1e5 + 10, SQ1 = 340, SQ2 = (maxn / SQ1) + 10; // SIZE // CNT
const int holy = 5e8;

int P, mod;

int a[maxn], n;

vector<int> open, close;
int pw[maxn], pwr[maxn];

struct block{
    vector<int> v, _v;
    int c, ch, _c, _ch;
    bool bad, _bad;    
    void build(int l, int r){
	open.clear(), close.clear();
	bad = 0;
	while(l < r){
	    if(a[l] < 0){
		if(sz(open)){
		    bad|= open.back() != -a[l];
		    open.pop_back();
		}
		else{
		    close.PB(-a[l]);
		}
	    }
	    else{
		open.PB(a[l]);
	    }
	    l++;
	}
	c = sz(close), ch = 0;
	for(int i = 0; i < sz(close); i++){
	    ch = (1ll * ch * P + close[i]) % mod;
	}
	v.clear();
	v.PB(0);
	for(int i = 0; i < sz(open); i++){
	    v.PB( (1ll * v.back() + 1ll * pw[i] * open[i]) % mod );
	}
    }
    void Swap(){
	swap(v, _v);
	swap(bad, _bad);
	swap(c, _c);
	swap(ch, _ch);
    }
};block b[SQ2];

int SZ[SQ2];
vector<int> poses;

bool solve(int l, int r){
    assert(l < r);
    for(int i = l; i < r; i++){
	SZ[i] = sz(b[i].v) - 1;
	if(b[i].bad)
	    return 0;
    }
    poses.clear();
    for(int i = l; i < r; i++){
	int num = 0, cnt = 0;
	while(sz(poses)){
	    int pt = poses.back();
	    if(cnt + SZ[pt] < b[i].c){
		num = (1ll * num * pw[SZ[pt]] + b[pt].v[ SZ[pt] ]) % mod;
		cnt+= SZ[pt];
		poses.pop_back();
	    }
	    else{
		int k = b[i].c - cnt;
		num = (1ll * num * pw[k] + 1ll * (b[pt].v[ SZ[pt] ] - b[pt].v[ SZ[pt] - k ]) * pwr[ SZ[pt] - k ]) % mod;
		if(num < 0)
		    num+= mod;
		SZ[pt]-= k;
		cnt = b[i].c;
		break;
	    }
	}
	if(poses.empty() && cnt != b[i].c){
	    return 0;
	}
	if(num != b[i].ch){
	    return 0;
	}
	poses.PB(i);
    }
    while(sz(poses)){
	if(SZ[poses.back()])
	    return 0;
	poses.pop_back();
    }
    return 1;
}

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;
}

bool prime(int x){
    for(int i = 2; i * i <= x; i++)
	if(x % i == 0)
	    return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    srand(time(0));
    P = (holy + (rand() % holy));
    mod = (holy + holy + (rand() % holy));
    while(!prime(P))
	P++;
    while(!prime(mod))
	mod++;
    
    pw[0] = 1;
    for(int i = 1; i < maxn; i++)
	pw[i] = 1ll * pw[i-1] * P % mod;
    pwr[maxn-1] = Pow(pw[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--)
	pwr[i] = 1ll * pwr[i + 1] * P % mod;
    
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    for(int i = 0; i * SQ1 < n; i++){
	b[i].build(i * SQ1, min(n, i * SQ1 + SQ1));
    }
    int q;
    cin >> q;
    vector<int> toSwap;
    while(q--){
	int task;
	cin >> task;
	int l, r;
	cin >> l >> r;
	--l;
	if(task == 1){
	    a[l] = r;
	    int id = l / SQ1;
	    b[id].build(id * SQ1, min(n, id * SQ1 + SQ1));
	}
	else{
	    toSwap.clear();
	    int idL = l/SQ1;
	    b[idL].Swap();
	    b[idL].build(l, min(r, idL * SQ1 + SQ1));
	    toSwap.PB(idL);
	    l = idL * SQ1 + SQ1;
	    int idR = idL;
	    while(l + SQ1 <= r){	     
		idR++;
		l+= SQ1;
	    }
	    if(l < r){
		idR++;
		b[idR].Swap();
		b[idR].build(l, r);
		toSwap.PB(idR);
	    }
	    
	    cout << (solve(idL, idR + 1) ? "Yes\n" : "No\n");
		
	    for(int id : toSwap){
		b[id].Swap();
	    }
	}
    }
    return 0;
}