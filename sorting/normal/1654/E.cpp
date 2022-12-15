#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 3;
const int C = 330;

const int MAX = 2 * (C + 1) * N;

int n, a[N], ans;

int c[MAX];
int *cnt = c + (MAX / 2);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    ans = n;

    for(int j = 1; j <= n; ++j){
        int l = max(j - C, 1);
        int r = min(j + C, n);
        
        int mx = 0;
        for(int i = l; i <= r; ++i){
            if(i == j) continue;

            if((a[j] - a[i]) % (j - i) == 0){
                int t = (a[j] - a[i]) / (j - i);
                ++cnt[t];
                if(cnt[t] > mx)
                    mx = cnt[t];
            }
        }

        for(int i = l; i <= r; ++i){
            if(i == j) continue;

            if((a[j] - a[i]) % (j - i) == 0){
                int t = (a[j] - a[i]) / (j - i);
                --cnt[t];
            }
        }

        ++mx;
        check_min(ans, n - mx);
    }

    for(int i = -C; i <= C; ++i){
        int mx = 0;
        for(int j = 1; j <= n; ++j){
            int t = a[j] - j * i;
            ++cnt[t];
            if(cnt[t] > mx)
                mx = cnt[t];
        }
        for(int j = 1; j <= n; ++j)
            --cnt[a[j] - j * i];

        check_min(ans, n - mx);
    }

    cout << ans << "\n";
}