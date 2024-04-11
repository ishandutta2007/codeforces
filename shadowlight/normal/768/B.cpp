#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5 + 7;

vector <pair <long long, long long> > data;
vector <long long> a;
pair <long long, long long> func(long long x) {
    if (x < 2) {
        data.push_back({1, x % 2});
        a.push_back(x);
        return data.back();
    }
    auto p = func(x / 2);
    data.push_back({2 * p.first + 1, 2 * p.second + x % 2});
    a.push_back(x);
    return data.back();
}

long long n, l, r;

long long cnt(long long l1, long long r1, long long now) {
    if (l > r1 || l1 > r) {
        return 0;
    }
    if (l <= l1 && r1 <= r) {
        return data[now].second;
    }
    long long mid = (l1 + r1) / 2;
    long long sum = cnt(l1, mid - 1, now - 1) + cnt(mid + 1, r1, now - 1);
    if (mid >= l && mid <= r) {
        sum += a[now] % 2;
    }
    //cout << l << " " << r << " " << l1 << " " << r1 << " " << now << " " << sum << endl;
    return sum;
}
int main() {
    cin >> n >> l >> r;
    func(n);
    cout << cnt(1, data.back().first, data.size() - 1);
}