#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
map<int, int> M;
int m;

ll fast_pow(ll base, ll k) {
    if(k == 0) return 1;
    if(k % 2 == 1) return (fast_pow(base, k-1) * base) % (mod);
    else {
        ll t = fast_pow(base, k/2);
        return (t * t) % (mod);
    }
}

int main() {
    scanf("%d", &m);
    int tmp;
    for(int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        if(M.count(tmp)) M[tmp]++;
        else M[tmp] = 1;
    }
    ll prod = 1;
    for(map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
        //cout << it->first << " " << it->second << endl;
        prod = (prod * ((it->second) + 1)) % (2*mod-2);
    }
    //cout << prod << endl;
    ll res = 1;
    for(map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
        ll base = it->first;
        ll exp = it->second;
        res = (res * fast_pow(base, ((exp * prod) % (2*mod-2)) / 2)) % mod;
        //res = (res * fast_pow(fast_pow(base, (diva ? exp : exp/2)), prod)) % mod;
    }
    //cout << prod << endl;
    cout << res;
}