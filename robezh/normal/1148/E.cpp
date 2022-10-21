#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
const int N = (int)3e5 + 50;

struct P {
    int i, j, d;
};

int n;
int a[N], b[N];
Pi ap[N], bp[N];
vector<P> res;

int main() {
    cin >> n;
    ll suma = 0, sumb = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i], suma += a[i];
        ap[i].first = a[i];
        ap[i].second = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i], sumb += b[i];
    }
    if(suma != sumb) return cout << "NO" << endl, 0;

    sort(a, a + n);
    sort(b, b + n);
    sort(ap, ap + n);
    int r = 0;
    while(r < n && a[r] < b[r]) r++;
    for(int i = 0; i < n; i++)  {
        if(a[i] > b[i]) return cout << "NO" << endl, 0;
        while(a[i] < b[i]) {
            while(r < n && a[r] <= b[r]) r++;
            int d = min(b[i] - a[i], a[r] - b[r]);
            a[i] += d;
            a[r] -= d;
            res.push_back({ap[i].second, ap[r].second, d});
        }
    }
    cout << "YES" << "\n";
    cout << res.size() << "\n";
    for(const auto &p : res) cout << p.i + 1 << " " << p.j + 1 << " " << p.d << "\n";


}