#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
int n, k, a[N], ans, r, cnt, x, y;
int cnt_el[N];

void add(int x){
    cnt += cnt_el[x];
}

void rem(int x){
    cnt -= cnt_el[x];
}

void solve(){
    cin >> n >> k;
    fill(cnt_el, cnt_el + n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ++cnt_el[a[i]];
    }

    ans = n;
    r = 0;
    cnt = 0;
    for(int l = 1; l <= n; ++l){
        while(r != n && cnt - (n - cnt) < k)
            add(++r);
        if(cnt - (n - cnt) >= k){
            if(r - l < ans){
                ans = r - l;
                x = l;
                y = r;
            }
        }
        rem(l);
    }

    cout << x << " " << y << "\n";
    int cnt = 0, start = 1;
    vector<pair<int, int>> limits;
    for(int i = 1; i <= n; ++i){
        if(x <= a[i] && a[i] <= y)
            ++cnt;
        else
            --cnt;

        if(cnt >= 1 && k > 1){
            cnt = 0;
            limits.push_back({start, i});
            start = i + 1;
            --k;
        }
    }
    limits.push_back({start, n});

    for(auto [l, r]: limits)
        cout << l << " " << r << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}