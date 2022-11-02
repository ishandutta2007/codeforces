#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100

ll b[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    while(n --) {
        int type;
        ll x, k;
        cin >> type >> x;
        ll y = x;
        int l = 0;
        while(y > 1) y >>= 1, l ++;
        if(type < 3) {
            cin >> k;
            k %= (1ll<<l);
            for(; l < N; l ++, k *= 2) {
                b[l] = ((b[l] + k) % (1ll<<l) + (1ll<<l)) % (1ll<<l);
                if(type == 1) break;
            }
        }
        if(type == 3) {
            x = (x+b[l]) % (1ll<<l);
            while(l) {
                cout << (x - b[l] + (1ll<<l)) % (1ll<<l) + (1ll<<l) << ' ';
                x >>= 1;
                l --;
            }
            cout << '1' << endl;
        }
    }
}