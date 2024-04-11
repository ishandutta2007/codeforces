#include <bits/stdc++.h>
using namespace std;

int a[100000];
bool prime[100000];
map<vector<pair<int, int>>, int> mp;
vector<int> primeSet;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<100000; p++)
        if (prime[p]) {
            primeSet.push_back(p);
            for (int i=p*p; i<100000; i+=p)
                prime[i] = false;
        }

    int n, k;
    long long ret = 0;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        vector<pair<int, int>> l, cl;
        for (int p : primeSet) {
            int cnt = 0;
            while (a[i] % p == 0) {
                a[i] /= p;
                cnt = (cnt + 1) % k;
            }
            if (cnt > 0) {
                l.push_back(make_pair(p, cnt));
                cl.push_back(make_pair(p, k - cnt));
            }
        }
        if (a[i] > 1) {
            l.push_back(make_pair(a[i], 1));
            cl.push_back(make_pair(a[i], k - 1));
        }
        ret += mp[cl];
        mp[l]++;
    }

    cout << ret << "\n";

    return 0;
}