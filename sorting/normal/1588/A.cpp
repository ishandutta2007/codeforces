#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 100 + 3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a_cnt(2 * N), b_cnt(2 * N);
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            ++a_cnt[x + N];
        }
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            ++b_cnt[x + N];
        }

        bool ok = true;
        for(int i = 2 * N - 1; i > 0; --i){
            if(a_cnt[i] > b_cnt[i]){
                ok = false;
                break;
            }
            int t = b_cnt[i] - a_cnt[i];
            if(t > a_cnt[i - 1]){
                ok = false;
                break;
            }
            a_cnt[i - 1] -= t;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}