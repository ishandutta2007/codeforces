#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
    register char c = getchar();
    register int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    return x * f;
}

int n, m, a[50005], b[50005];
vector <pair <long long, long long> > va, vb;

inline void Read() {
    cin >> n >> m;
    va.clear(); vb.clear();
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        long long fac = 1;
        while (a[i] % m == 0) {
            a[i] /= m;
            fac *= m;
        }
        if (!va.empty() && va.back().first == a[i]) va[va.size() - 1].second += fac;
        else va.push_back(make_pair(a[i], fac));
    }
    int k;
    cin >> k;
    for (int i = 1;i <= k;i++) {
        cin >> b[i];
        long long fac = 1;
        while (b[i] % m == 0) {
            b[i] /= m;
            fac *= m;
        }
        if (!vb.empty() && vb.back().first == b[i]) vb[vb.size() - 1].second += fac;
        else vb.push_back(make_pair(b[i], fac));
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        Read();
        // for (pair <long long, long long> x : va) cout << x.first << "," << x.second << " "; cout << endl;
        if (va != vb) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}