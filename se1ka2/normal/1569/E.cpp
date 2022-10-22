#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll p[22];
int c[35];

ll calc_hash(ll b, int k, bool latter, bool top){
    int d[34];
    for(int i = 0; i < (1 << (k - 1)); i++){
        d[i + (1 << (k - 1))] = i + 1;
        if(latter) d[i + (1 << (k - 1))] += (1 << (k - 1));
    }
    ll s = 0;
    for(int i = (1 << (k - 1)) - 1; i >= 1; i--){
        d[i] = d[i * 2 + ((b >> i) & 1)];
        s = (s + d[i * 2 + !((b >> i) & 1)] * p[c[i]]) % MOD;
    }
    if(top) return (s + d[1] * p[1]) % MOD;
    else return (s + d[1] * p[2]) % MOD;
}

vector<int> ans(ll b, int k, bool top){
    vector<int> res(1 << (k - 1));
    int d[70];
    for(int i = 0; i < (1 << (k - 1)); i++) d[i + (1 << (k - 1))] = i;
    for(int i = (1 << (k - 1)) - 1; i >= 1; i--){
        d[i] = d[i * 2 + ((b >> i) & 1)];
        res[d[i * 2 + !((b >> i) & 1)]] = c[i];
    }
    res[d[1]] = 2 - top;
    return res;
}

int main()
{
    int k;
    ll a, h;
    cin >> k >> a >> h;
    p[0] = 1;
    for(int i = 1; i < 20; i++) p[i] = p[i - 1] * a % MOD;
    for(int i = 0; i < k - 1; i++){
        for(int j = (1 << i); j < (1 << (i + 1)); j++) c[j] = (1 << i) * 2 + 1;
    }
    set<ll> st1, st2;
    for(ll b = 0; b < (1 << (1 << (k - 1))); b += 2){
        st1.insert(calc_hash(b, k, false, true));
        st2.insert(calc_hash(b, k, false, false));
    }
    for(ll b = 0; b < (1 << (1 << (k - 1))); b += 2){
        if(st2.find((h + MOD - calc_hash(b, k, true, true)) % MOD) != st2.end()){
            for(int a = 0; a < (1 << (1 << (k - 1))); a += 2){
                if((calc_hash(a, k, false, false) + calc_hash(b, k, true, true)) % MOD == h){
                    vector<int> l = ans(a, k, false), r = ans(b, k, true);
                    for(int i : l) cout << i << " ";
                    for(int i : r) cout << i << " ";
                    cout << endl;
                    return 0;
                }
            }
        }
        if(st1.find((h + MOD - calc_hash(b, k, true, false)) % MOD) != st1.end()){
            for(int a = 0; a < (1 << (1 << (k - 1))); a += 2){
                if((calc_hash(a, k, false, true) + calc_hash(b, k, true, false)) % MOD == h){
                    vector<int> l = ans(a, k, true), r = ans(b, k, false);
                    for(int i : l) cout << i << " ";
                    for(int i : r) cout << i << " ";
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
}