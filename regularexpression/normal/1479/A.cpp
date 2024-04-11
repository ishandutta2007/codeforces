#include <bits/stdc++.h>
using namespace std;

const vector<int> a = {3, 2, 1, 4, 5};

int n;

int query(int i) {
    if (i == 0 || i == n + 1) 
        return n + 1;
    cout << "? " << i << endl;
    int res;
    cin >> res;
    return res;
}

bool check(int i) {
    return query(i) < query(i - 1) && query(i) < query(i + 1);
}

void answer(int k) {
    cout << "! " << k << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int l = 1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (query(m) > query(m + 1)) 
            l = m;
        else
            r = m;
    }
    for (int i = l; i <= r; i++) {
        if (check(i)) 
            answer(i);
    }
    return 0;
}