#include <bits/stdc++.h>
#include <queue>
using namespace std;
const long long N = 2e5 + 5, base = 10007, MOD = 1e14 + 7;
int n, m, res, num[N];
vector<int> a[N];
queue<long long> Q;

struct Data{
    int c[11];
    long long Compress() {
        long long z = 0;
        for(int i=0; i<n; ++i)
            z =(z * base + c[i]) % MOD;
        return z;
    }
} w, ans;
map<long long, Data> M;
map<long long, bool> Rem;

void calculate(Data W) {
    int sum = 0;
    for(int i=0; i<n; ++i) sum += a[i][W.c[i]];
    if (res < sum) {
        res = sum;
        ans = W;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> num[i];
        int x;
        for(int j=0; j<num[i]; ++j) cin >> x, a[i].push_back(x);
    }
    cin >> m;
    while (m--) {
        for(int i=0; i<n; ++i) cin >> w.c[i], --w.c[i];
        Rem[w.Compress()] = true;
    }
    for(int i=0; i<n; ++i) w.c[i] = num[i] - 1;

    long long z = w.Compress();
    Q.push(z); M[z] = w;
    while (!Q.empty()) {
        z = Q.front(); Q.pop();
        if (!Rem.count(z))
            calculate(M[z]);
        else {
            w = M[z];
            for(int i=0; i<n; ++i) if (w.c[i]) {
                --w.c[i];
                long long z2 = w.Compress();
                if (!M.count(z2)) {
                    Q.push(z2);
                    M[z2] = w;
                }
                ++w.c[i];
            }
        }
    }
    for(int i=0; i<n; ++i) cout << ans.c[i] + 1 << ' ';
}