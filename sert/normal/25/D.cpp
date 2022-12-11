#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int p[N];
vector <pair<int, int> > v;
vector <int> t;
int fnd(int v) {
    return (p[v] == v ? v : p[v] = fnd(p[v]));
}
void uniq(int v1, int v2) {
    p[fnd(v1)] = fnd(v2);
}

int main() {
    init();
    int n, v1, v2;
    cin >> n;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        if (fnd(v1) == fnd(v2))
            v.push_back(make_pair(v1, v2));
        else
            uniq(v1, v2);
    }
    cout << v.size() << "\n";
    for (int i = 1; i <= n; i++)
        if (p[i] == i)
            t.push_back(i);
    for (int i = 1; i < t.size(); i++) {
        cout << v[i - 1].first << " " << v[i - 1].second << " " << t[0] << " " << t[i] << "\n";
    }


    return 0;
}