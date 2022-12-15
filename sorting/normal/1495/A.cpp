#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

long double get_dist(pair<int, int> a, pair<int, int> b){
    auto [ax, ay] = a;
    auto [bx, by] = b;
    return sqrt((long double)(ax - bx) * (ax - bx) + (long double)(ay - by) * (ay - by));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<pair<int, int>> a, b;
        for(int i = 0; i < 2 * n; ++i){
            int x, y;
            cin >> x >> y;
            if(x) a.push_back({abs(x), abs(y)});
            else b.push_back({abs(x), abs(y)});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long double ans = 0;
        for(int i = 0; i < n; ++i)
            ans += get_dist(a[i], b[i]);
        cout << fixed << setprecision(12) << ans << "\n";
    }
}