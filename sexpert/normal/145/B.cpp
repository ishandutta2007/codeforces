#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int can(int c4, int c7, int c47, int c74) {
    if(fabs(c47 - c74) > 1)
        return -1;
    if(c4 > 0 && c7 > 0 && c47 == 0 && c74 == 0)
        return -1;
    if((c4 == 0 || c7 == 0) && c47 + c74 > 0)
        return -1;
    if(c47 == c74) {
        // ABABA
        int common = c47;
        if(c4 >= 1 && c4 >= common + 1 && c7 >= common)
            return 2;
        if(c7 >= common + 1 && c4 >= common)
            return 1;
        return -1;
    }
    if(c47 == c74 + 1) {
        // 474747
        int fir = c47;
        if(c4 >= 1 && c4 >= fir && c7 >= fir)
            return 2;
        return -1;
    }
    //747474
    int fir = c74;
    if(c7 >= fir && c4 >= fir)
        return 1;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = can(a, b, c, d);
    if(x == -1) {
        cout << "-1\n";
        return 0;
    }
    string ans;
    if(x == 2) {
        ans += '4';
        a--;
    }
    else {
        ans += '7';
        b--;
    }
    while(a > 0 || b > 0) {
        if(ans.back() == '4')
            x = can(a, b, c, d);
        else
            x = can(a, b, c, d - 1);
        if(x == 2) {
            a--;
            if(ans.back() == '7')
                d--;
            ans += '4';
            continue;
        }
        b--;
        if(ans.back() == '4')
            c--;
        ans += '7';
    }
    cout << ans << '\n';
}