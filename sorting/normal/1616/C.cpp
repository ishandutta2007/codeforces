#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        int ans = n - 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                int cand = n - 1;

                pair<int, int> diff = {a[i] - a[j], i - j};
                int g;
                g = __gcd(diff.first, diff.second);
            
                if(!g){
                    diff.second = 1;
                }
                else{
                    diff.first /= g;
                    diff.second /= g;
                }

                if(diff.second < 0){
                    diff.first = -diff.first;
                    diff.second = -diff.second;
                }

                for(int k = i - diff.second; k >= 0; k -= diff.second){
                    if(a[k] == a[i] - diff.first * ((i - k) / diff.second))
                        --cand;
                }
                for(int k = i + diff.second; k <= n - 1; k += diff.second){
                    if(a[k] == a[i] + diff.first * ((k - i) / diff.second))
                        --cand;
                }

                check_min(ans, cand);
            }
        }
        cout << ans << "\n";
    }
}