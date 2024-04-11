#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;



int main() {
    int m, n;
    cin >> m >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cout << m << endl;
        int a;
        cin >> a;

        if(a == 0)
            return 0;

        p[i] = (a == -1);
    }

    int l = 1, r = m + 1;
    int i = 0;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        cout << mid << endl;
        int a;
        cin >> a;

        if(a == 0)
            return 0;

        if(p[i] ^ (a == 1))
            r = mid;
        else
            l = mid + 1;

        i = (i + 1) % n;
    }

    cout << l << endl;
}