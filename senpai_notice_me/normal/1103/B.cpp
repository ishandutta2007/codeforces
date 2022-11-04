#include <bits/stdc++.h>

using namespace std;

string in_str;

void query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    cin >> in_str;
}

void answer(int x) {
    printf("! %d\n", x);
    fflush(stdout);
    cin >> in_str;
}

void solve() { // for each game
    int l, r;
    for (int i = 1; i <= (int)1e9; i *= 2) {
        query(i - 1, i * 2 - 1);
        if (in_str == "x") {
            l = i, r = i * 2 - 1;
            break;
        }
    }
    
    r = min(r, (int)1e9);
    
    while (l < r) {
        int mid = (l + r) / 2;
        query(l - 1, mid);
        assert(in_str != "e"); // RE
        if (in_str == "x") {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    answer(l);
}

int main() {
    cin >> in_str;
    while (in_str == "start") {
        solve();
    }
    
    return 0;
}