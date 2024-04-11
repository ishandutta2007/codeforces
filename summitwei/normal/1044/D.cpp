#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int q;
map<int, int> nodes;

int t;
int make(int x){
    if(nodes.count(x)) return nodes[x];
    nodes[x] = ++t;
    return nodes[x];
}

int dsu[2*MN];
int sz[2*MN];
int toPar[2*MN];
int fd(int x){
    if(x == dsu[x]) return x;
    return fd(dsu[x]);
}
int calc(int x){
    if(x == dsu[x]) return 0;
    return toPar[x] ^ calc(dsu[x]);
}
void jn(int x, int y, int d){
    d ^= calc(x); d ^= calc(y);
    x = fd(x); y = fd(y);
    //cout << "joining " << x << " " << y << "\n";
    if(x == y) return;
    //cout << "wtmoo\n";
    if(sz[x] < sz[y]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
    toPar[y] = d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 1, 2*MN-5){
        dsu[i] = i;
        sz[i] = 1;
    }
    
    cin >> q;
    int pv = 0;
    F0R(_, q){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            l ^= pv; r ^= pv; x ^= pv;
            if(l > r) swap(l, r);
            ++r;
            //cout << l << " " << r << " " << x << "\n";
            l = make(l); r = make(r);
            jn(l, r, x);
        } else if(t == 2){
            int l, r;
            cin >> l >> r;
            l ^= pv; r ^= pv;
            if(l > r) swap(l, r);
            ++r;
            //cout << l << " " << r << "\n";
            l = make(l); r = make(r);
            //cout << fd(l) << " " << fd(r) << "\n";
            if(fd(l) != fd(r)){
                cout << "-1\n";
                pv = 1;
            } else{
                int res = calc(l)^calc(r);
                //cout << "got " << calc(l) << " " << calc(r) << "\n";
                cout << res << "\n";
                pv = res;
            }
        }
        /*FOR(i, 1, 8){
            cout << dsu[i] << " ";
        }
        cout << "\n";*/
    }

    return 0;
}