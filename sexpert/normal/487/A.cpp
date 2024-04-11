#include <bits/stdc++.h>
using namespace std;

int hy, ay, dy, hm, am, dm, h, a, d;

bool check(int h1, int a1, int d1, int h2, int a2, int d2) {
    int dec1 = max(a1 - d2, 0), dec2 = max(a2 - d1, 0);
    if(dec1 == 0)
        return false;
    int tur = (dec2 ? (h1 - 1)/dec2 : INT_MAX);
    int kil = (h2 - 1)/dec1 + 1;
    /*if(h1 == 100 && a1 == 2 && d1 == 1) {
        cout << tur << " " << kil << endl;
    }*/
    return kil <= tur;
}

int main() {
    cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
    int ans = INT_MAX;
    for(int hp = 0; hp <= 1000; hp++) {
        for(int ap = 0; ap <= 200; ap++) {
            for(int dp = 0; dp <= 100; dp++) {
                if(check(hy + hp, ay + ap, dy + dp, hm, am, dm))
                    ans = min(ans, h*hp + a*ap + d*dp);
            }
        }
    }
    cout << ans << '\n';
}