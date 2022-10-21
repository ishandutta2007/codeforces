#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n;
int x[N], mu[N];
vi dvs[N];
int cnt[N];
stack<int> S;

int num_coprime(int x) {
    int res = 0;
    for(int d : dvs[x]) {
        res += cnt[d] * mu[d];
    }
    return res;
}

void add(int x, int val) {
    for(int d : dvs[x]) cnt[d] += val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int y; cin >> y; x[y] = 1;
    }
    mu[1] = 1;
    for(int i = 1; i < N; i++) {
        dvs[i].push_back(i);
        for(int j = 2 * i; j < N; j += i) {
            x[i] |= x[j];
            mu[j] -= mu[i];
            dvs[j].push_back(i);
        }
    }
    ll res = 1;
    for(int i = N - 1; i >= 0; i--) {
        if(!x[i]) continue;
        int c = num_coprime(i);
        while(c) {
            int s = S.top(); S.pop();
            add(s, -1);
            if(__gcd(s, i) == 1) {
                res = max(res, 1LL * s * i);
                c--;
            }
        }
        S.push(i);
        add(i, 1);
    }
    cout << res << '\n';

}