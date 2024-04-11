#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2000000;

int sieve[MAXN];

int dig[32];
bool palin(int a){
    int D = 0;
    while(a) {
        dig[D++] = a%10;
        a /= 10;
    }

    for (int i = 0; i < D; i++)
        if(dig[i] != dig[D-1-i]) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (ll p = 2; p < MAXN; p++) {
        if(sieve[p]) continue;
        for (ll q = p; q < MAXN; q += p) {
            sieve[q] = p;
        }
    }

    ll P, Q;
    cin >> P >> Q;

    int ans = 0;
    int pri = 0, pal = 0;

    for (int i = 1; i < MAXN; i++) {
        if(sieve[i] == i) pri++;
        if(palin(i)) pal++;

        if(pri <= P * pal / Q) ans = i;
    }

    cout << ans << endl;
}