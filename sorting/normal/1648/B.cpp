#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;

int n, c, a[N];
bool b[N];
vector<int> d[N];

int cnt[N];
int cnt_ok;
bool in_a[N];

void solve(){
    cin >> n >> c;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - (a + 1);

    fill(in_a + 1, in_a + 1 + c, false);
    for(int i = 1; i <= n; ++i)
        in_a[a[i]] = true;

    fill(d + 1, d + 1 + c, vector<int>()); 

    for(int i = 1; i <= n; ++i){
        for(int j = a[i]; j <= c; j += a[i])
            d[j].push_back(a[i]);
    }

    fill(cnt + 1, cnt + 1 + c, 0);
    cnt_ok = n;
    in_a[0] = true;

    for(int i = 1; i <= n; ++i){
        for(int j = a[i - 1] + 1; j <= a[i]; ++j){
            for(int dd: d[j]){
                cnt[dd]++;
                cnt_ok -= in_a[cnt[dd] - 1];
                cnt_ok += in_a[cnt[dd]];
            }
        }

        if(cnt_ok != n){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}