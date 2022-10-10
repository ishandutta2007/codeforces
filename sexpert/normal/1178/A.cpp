#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int use[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int tot = accumulate(v.begin(), v.end(), 0);
    int bnd = v[0]/2;
    int sum = v[0], cnt = 1;
    use[0] = 1;
    for(int i = 1; i < n; i++) {
        if(v[i] <= bnd) {
            use[i] = 1;
            sum += v[i];
            cnt++;
        }
    }
    if(sum <= tot - sum) {
        cout << "0\n";
        return 0;
    }
    cout << cnt << '\n';
    for(int i = 0; i < n; i++){
        if(use[i])
            cout << i + 1 << " ";
    }
    cout << '\n';
}