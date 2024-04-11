#include <bits/stdc++.h>

using namespace std;

int main() {
    long long s, x;
    cin >> s >> x;

    int cnt = 0;
    long long ans = 0;
    if(s == x)
        ans -= 2;
    for(int i = 0; i <= 60; i++) {
        if((1ll << i) & x) {
            cnt++;
            s -= (1ll << i);
        }
    }

    for(int i = 0; i <= 60; i++) {
        if(((1ll << i) & x) == 0) {
            if(s & (1ll << (i + 1)))
                s -= (1ll << (i + 1));
        }
    }

     ans += (1ll << cnt);



    if(s == 0)
        cout << ans;
    else
        cout << 0;
}