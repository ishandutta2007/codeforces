#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int n;
long long bit[100001] = {};

long long query(int x) {
    long long ret = 0;
    for (int i=x; i>0; i-=i&-i)
        ret = max(ret, bit[i]);
    return ret;
}

void update(int x, long long val) {
    for (int i=x; i<=n; i+=i&-i)
        bit[i] = max(bit[i], val);
}

long long a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    vector<long long> v;
    for (int i=0; i<n; i++) {
        int r, h;
        cin >> r >> h;
        a[i] = (long long) r * r * h;
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    unordered_map<long long, int> compression;
    for (int i=0; i<n; i++)
        compression[v[i]] = i + 1;

    long long ret = 0;
    for (int i=0; i<n; i++) {
        long long val = query(compression[a[i]] - 1);
        ret = max(ret, val + a[i]);
        update(compression[a[i]], val + a[i]);
    }

    cout << fixed << setprecision(10) << ret * PI << "\n";

    return 0;
}