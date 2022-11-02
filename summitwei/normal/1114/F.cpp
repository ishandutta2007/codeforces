#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 400005
#define MK 305
int n, q;
int a[MN];
pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }
 
    pll prev = gcd(b%a, a);
 
    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues
ll modInv(ll x){ //return x^-1 % MOD
    pll res = gcd(x, MOD);
 
    res.f = (res.f+MOD)%MOD;
 
    //cout << "modinv of " << x << " is " << res.f << "\n";
 
    return res.f;
}
ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}
ll invpr[MN]; //(a-1)/a
vi pri;
map<int, int> pr;
int val[MK];
void sieve(){
    FOR(i, 2, 300){
        //cout << "doing " << i << "\n";
        if(val[i] == 0){
            pr[i] = 0;
            pri.pb(i);
            for(int j=i; j<=300; j+=i){
                val[j] = i;
            }
        }
    }
}

ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}
ll st[MN][2];
ll bm[MK];
ll tree[4*MN][2];
ll lazy[4*MN][2];
void init(int node, int a, int b, int t){
    if(t == 0) lazy[node][t] = 1;
	if (a == b) {
		tree[node][t] = st[a][t];
		return;
	}
	int mid = (a + b) / 2;
	init(node * 2, a, mid, t);
	init(node * 2 + 1, mid + 1, b, t);
	if(t == 0){
        tree[node][t] = (tree[node*2][t]*tree[node*2+1][t])%MOD;
    } else{
        tree[node][t] = tree[node*2][t]|tree[node*2+1][t];
    }
}
void upd(int node, int a, int b, int i, int j, ll val, int t){
	if(lazy[node][t] != 1-t){
        if(t == 0){
            tree[node][t] = (tree[node][t]*modExp(lazy[node][t], b-a+1))%MOD;
            if(a != b){
                lazy[node*2][t] = (lazy[node][t]*lazy[node*2][t])%MOD;
                lazy[node*2+1][t] = (lazy[node][t]*lazy[node*2+1][t])%MOD;
            }
        } else{
            tree[node][t] |= lazy[node][t];
            if(a != b){
                lazy[node*2][t] |= lazy[node][t];
                lazy[node*2+1][t] |= lazy[node][t];
            }
        }
		lazy[node][t] = 1-t;
	}
	if(a > j || b < i) return;
	if(i <= a && b <= j){
        if(t == 0){
            tree[node][t] = (tree[node][t]*modExp(val, b-a+1))%MOD;
            if(a != b){
                lazy[node*2][t] = (lazy[node*2][t]*val)%MOD;
                lazy[node*2+1][t] = (lazy[node*2+1][t]*val)%MOD;
            }
        } else{
            tree[node][t] |= val;
            if(a != b){
                lazy[node*2][t] |= val;
                lazy[node*2+1][t] |= val;
            }
        }
		return;
	}
	int mid = (a+b)/2;
	upd(node * 2, a, mid, i, j, val, t);
	upd(node * 2 + 1, mid + 1, b, i, j, val, t);
	if(t == 0){
        tree[node][t] = (tree[node*2][t]*tree[node*2+1][t])%MOD;
    } else{
        tree[node][t] = tree[node*2][t]|tree[node*2+1][t];
    }
}
ll que(int node, int a, int b, int i, int j, int t){
	if(lazy[node][t] != 1-t){
        if(t == 0){
            tree[node][t] = (tree[node][t]*modExp(lazy[node][t], b-a+1))%MOD;
            if(a != b){
                lazy[node*2][t] = (lazy[node][t]*lazy[node*2][t])%MOD;
                lazy[node*2+1][t] = (lazy[node][t]*lazy[node*2+1][t])%MOD;
            }
        } else{
            tree[node][t] |= lazy[node][t];
            if(a != b){
                lazy[node*2][t] |= lazy[node][t];
                lazy[node*2+1][t] |= lazy[node][t];
            }
        }
		lazy[node][t] = 1-t;
	}
	if(a > j || b < i) return 1-t;
	if (i <= a && b <= j) return tree[node][t];
	int mid = (a + b) / 2;
	ll q1 = que(node * 2, a, mid, i, j, t);
	ll q2 = que(node * 2 + 1, 1 + mid, b, i, j, t);
	if(t == 0) return (q1*q2)%MOD;
    else return q1|q2;
}
//bruh moment
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    sieve();
    //cout << "hi\n";
    int ti = 0;
    for(auto &u : pr){
        u.s = ti++;
    }
    //cout << pr.size() << "\n";
    FOR(i, 1, 300){
        int x = i;
        while(x != 1){
            int ree = pr[val[x]];
            bm[i] |= (1LL<<ree);
            x /= val[x];
        }
        invpr[i] = modDiv(i-1, i);
    }
    FOR(i, 1, n){
        cin >> a[i];
        st[i][0] = a[i];
        st[i][1] = bm[a[i]];
    }
    init(1, 1, n, 0);
    init(1, 1, n, 1);
    /*FOR(i, 1, 10){
        cout << tree[i][0] << " ";
    }
    cout << "\n";
    FOR(i, 1, 10){
        cout << tree[i][1] << " ";
    }
    cout << "\n";*/
    F0R(_, q){
        string s;
        cin >> s;
        if(s == "MULTIPLY"){
            int l, r; ll x;
            cin >> l >> r >> x;
            ll cbm = bm[x];
            upd(1, 1, n, l, r, x, 0);
            upd(1, 1, n, l, r, cbm, 1);
        } else{
            int l, r;
            cin >> l >> r;
            ll prod = que(1, 1, n, l, r, 0);
            ll bruh = que(1, 1, n, l, r, 1);
            //cout << prod << " " << bruh << "\n";
            F0R(i, pri.size()){
                if((1LL<<i)&bruh){
                    prod *= invpr[pri[i]];
                    prod %= MOD;
                }
            }
            cout << prod << "\n";
        }
    }

    return 0;
}