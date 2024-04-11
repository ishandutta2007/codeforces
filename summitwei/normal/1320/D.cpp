#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 1000000000000LL
#define MOD 1000000007LL
#define BRUH 97
#define IBR 268041239
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
string t;

int q;

int zct[MN]; //counts zeroes
ll hsh[MN];
ll exps[MN];
ll ibr[MN];
set<int> dbl;
ll zhsh[MN];
ll ozhsh[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    exps[0] = 1;
    ibr[0] = 1;
    FOR(i, 1, MN-2){
        exps[i] = (exps[i-1]*BRUH)%MOD;
        ibr[i] = (ibr[i-1]*IBR)%MOD;
    }

    cin >> n >> t;
    hsh[0] = (t[0]-'0');
    if(t[0] == '0'){
        zct[0] = 1;
        zhsh[0] = 0;
        ozhsh[0] = 1;
    }
    FOR(i, 1, n-1){
        hsh[i] = hsh[i-1]+exps[i]*(t[i]-'0');
        hsh[i] %= MOD;
        if(t[i] == t[i-1]){
            dbl.insert(i-1);
        }
        zhsh[i] = zhsh[i-1];
        ozhsh[i] = ozhsh[i-1];
        zct[i] = zct[i-1];
        if(t[i] == '0'){
            zhsh[i] = (zhsh[i]+exps[zct[i]]*(i%2))%MOD;
            ozhsh[i] = (ozhsh[i]+exps[zct[i]]*((i+1)%2))%MOD;
            ++zct[i];
        }
    }

    /*F0R(i, n){
        cout << i << " " << hsh[i] << " " << zct[i] << " " << zhsh[i] << " " << ozhsh[i] << "\n";
    }*/
    /*for(auto u : dbl) cout << u << " ";
    cout << "\n";*/

    cin >> q;
    F0R(i, q){
        int a, b, l;
        cin >> a >> b >> l;
        /*if(i == 93){
            cout << a << " " << b << " " << l << "\n";
            return 0;
        }
        cout << t.substr(a-1, l) << " " << t.substr(b-1, l) << "\n";*/
        --a; --b;
        ll ahs = hsh[a+l-1]-(a!=0?hsh[a-1]:0);
        ahs = (ahs+MOD)%MOD;
        ll bhs = hsh[b+l-1]-(b!=0?hsh[b-1]:0);
        bhs = (bhs+MOD)%MOD;
        ahs = (ahs*ibr[a])%MOD; bhs = (bhs*ibr[b])%MOD;
        if(ahs == bhs){
            //cout << "hsh equal\n";
            cout << "YES\n";
            continue;
        }
        set<int>::iterator res1 = dbl.lower_bound(a), res2 = dbl.lower_bound(b);
        if(res1 == dbl.end() || res2 == dbl.end() || *res1 > a+l-2 || *res2 > b+l-2){
            //cout << "no doubles\n";
            cout << "NO\n";
            continue;
        }
        ll azhs = zhsh[a+l-1]-(a!=0?zhsh[a-1]:0);
        azhs = (azhs+MOD)%MOD;
        ll bzhs;
        if(a%2 == b%2){
            bzhs = zhsh[b+l-1]-(b!=0?zhsh[b-1]:0);
        } else{
            //cout << "REE\n";
            bzhs = ozhsh[b+l-1]-(b!=0?ozhsh[b-1]:0);
        }
        bzhs = (bzhs+MOD)%MOD;
        //cout << azhs << " " << bzhs << "\n";
        azhs = (azhs*ibr[zct[a+l-1]])%MOD; bzhs = (bzhs*ibr[zct[b+l-1]])%MOD;
        //cout << azhs << " " << bzhs << "\n";
        int azct = zct[a+l-1]-(a!=0?zct[a-1]:0);
        int bzct = zct[b+l-1]-(b!=0?zct[b-1]:0);
        if(azct == bzct && azhs == bzhs){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}
/*
0011011100
0000101011
1101101001
0000010101
0000111111
1010100101
0110110011
0001000011
1001100111
1110100110

100
0011011100000010101111011010010000010101000011111110101001010110110011000100001110011001111110100110
1
84 97 3

10000111, 10010101*/