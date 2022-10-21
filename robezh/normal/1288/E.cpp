#include <bits/stdc++.h>
using namespace std;

const int N = (int)6e5 + 50;

struct BIT {

    int n;
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} bit;

int n, m;
vector<int> a;
int la[N];
int ansmin[N], ansmax[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        ansmin[i] = ansmax[i] = i;
    }
    for(int i = n - 1; i >= 0; i--) {
        a.push_back(i);
    }
    for(int i = 0; i < m; i++) {
        int x; cin >> x; x--;
        ansmin[x] = 0;
        a.push_back(x);
    }
    bit.n = a.size();
    fill(la, la + n, -1);
//    for(int x : a) cout << x << " ";
//    cout << endl;
    for(int i = 0; i < a.size(); i++) {
        if(la[a[i]] != -1) {
            ansmax[a[i]] = max(ansmax[a[i]], bit.get(la[a[i]] + 1, i - 1));
            bit.add(la[a[i]], -1);
        }

        la[a[i]] = i;
        bit.add(i, 1);

//        cout << i << ": ";
//        for(int j = 0; j < bit.n; j++) cout << bit.get(j, j) << " ";
//        cout << endl;
    }
    for(int j = 0; j < n; j++) ansmax[j] = max(ansmax[j], bit.get(la[j] + 1, bit.n - 1));
    for(int i = 0; i < n; i++) cout << ansmin[i] + 1 << " " << ansmax[i] + 1 << '\n';
}