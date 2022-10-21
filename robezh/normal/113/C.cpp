#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = (int)3e8 + 50;

bitset<M> p;

void sieve() {
    p.set();
    p[1] = false;
    for(int i = 2; i * i < M; i++) {
        if(!p[i]) continue;
        for(int j = 2 * i; j < M; j += i) {
            p[j] = false;
        }
    }
}

int main(){
    sieve();

    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for(int i = (l + 2) / 4 * 4 + 1; i <= r; i += 4) {
        if(p[i]) cnt++;
    }
    if(l <= 2 && 2 <= r) cnt++;
    cout << cnt << endl;
}