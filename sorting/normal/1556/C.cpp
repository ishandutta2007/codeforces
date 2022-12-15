#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &c, const T &b){ c = (c < b) ? c : b; }
template<class T> void check_max(T &c, const T &b){ c = (c > b) ? c : b; }

const int N = 1000 + 3;

int n, c[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> c[i];

    ll ans = 0;

    for(int i = 0; i < n - 1; i += 2){
        ll add = c[i], rem = 0;
        for(int j = i + 1; j < n; ++j){
            if(j & 1){
                if(c[j] <= rem){
                    rem -= c[j];
                    if(!rem) ans += 1;
                }
                else{
                    int cj = c[j];
                    cj -= rem;
                    rem = 0;
                    if(j != i + 1) ans += min((ll)cj, add) + 1;
                    else ans += min((ll)cj, add);
                    add -= cj;
                }
                if(add < 0) break;
            }
            else rem += c[j];
            //cout << ans << " - " << i << " " << j << endl;
        }
    }

    cout << ans << "\n";
}