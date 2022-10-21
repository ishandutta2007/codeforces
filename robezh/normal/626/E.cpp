#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const double EPS = 1e-6;

int n;
int a[N];
ll psum[N];
double res = -1;
vector<int> ele;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + a[i];
    double cur_res = -1;
    int ri = -1, seg = -1;
    for(int i = 2; i <= n - 1; i++) {
        int l = 0, r = min(i - 1, n - i), mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            ll sum = psum[i] - psum[i-mid-1] + psum[n] - psum[n-mid];
            ll cnt = mid * 2 + 1;
            ll sum2 = a[i-mid-1] + a[n-mid];
            if(sum2 * cnt < sum * 2) r = mid;
            else l = mid;
        }
        double p_res = 1.0 * (psum[i] - psum[i-r-1] + psum[n] - psum[n-r]) / (r * 2 + 1) - a[i];
        if(p_res > cur_res) cur_res = p_res, ri = i, seg = r;
    }
    res = cur_res;
    for(int i = ri - seg; i <= ri; i++) ele.push_back(a[i]);
    for(int i = n - seg + 1; i <= n; i++) ele.push_back(a[i]);

    if(res < 0) {
        cout << "1\n" << a[1] << "\n";
        return 0;
    }
    cout << ele.size() << endl;
    for(int x : ele) cout << x << " ";
    cout << endl;
}