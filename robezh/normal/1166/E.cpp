#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e4 + 50;
typedef long long ll;
typedef bitset<N> bs;

int n, m;
bs s[55];
bs tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int k, a;
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> a; a--;
            s[i].set(a);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            tmp = s[j];
            tmp.flip();
            int r_count = tmp.count();
//            cout << i << ", " << j << ": " << tmp << ", " << s[i] << endl;
            tmp |= s[i];
            if(tmp.count() == r_count) return cout << "impossible" << endl, 0;
        }
    }
    cout << "possible" << endl;
}