#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, c_good[5];
vector<array<int, 5>> v;

int get_sc(int solved, int total) {
    if(solved * 32 <= total)
        return 6;
    if(solved * 16 <= total)
        return 5;
    if(solved * 8 <= total)
        return 4;
    if(solved * 4 <= total)
        return 3;
    if(solved * 2 <= total)
        return 2;
    return 1;
}

bool can(int m) {
    int tot = 0;
    for(int i = 0; i < 5; i++) {
        int d = v[1][i] - v[0][i];
        if(d < 0) {
            // minimize score
            if(v[0][i] < 250)
                tot += d * get_sc(c_good[i] + m, n + m);
            else
                tot += d * get_sc(c_good[i], n + m);
        }
        else {
            // maximize score
            tot += d * get_sc(c_good[i], n + m);
        }
    }
    return tot > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for(auto &x : v) {
        for(int i = 0; i < 5; i++) {
            cin >> x[i];
            if(x[i] == -1)
                x[i] = 250;
            else
                c_good[i]++;
        }
    }

    for(int m = 0; m <= 5000; m++) {
        if(can(m)) {
            cout << m << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}