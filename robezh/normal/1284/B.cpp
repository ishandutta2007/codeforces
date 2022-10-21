#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;

int n;
int mx[N], mn[N];
int tn;
int freq[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int m; cin >> m;
        vector<int> x(m, 0);
        bool out = false;
        for(int j = 0; j < m; j++) {
            cin >> x[j];
            if(j >= 1 && x[j] > x[j - 1]) out = true;
        }
        if(!out) {
            mx[tn] = x[0];
            mn[tn] = x.back();
            tn++;
        }
    }
    ll res = 1LL * (n - tn) * (n + tn);
//    cout << res << endl;
    n = tn;
    for(int i = 0; i < n; i++) {
        freq[mx[i]]++;
    }
    for(int i = N - 2; i >= 0; i--) {
        freq[i] += freq[i+1];
    }
    for(int i = 0; i < n; i++) {
        res += freq[mn[i] + 1];
    }
    cout << res << '\n';
}