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
        int n, k;
        cin >> n >> k;

        vector<string> ans(n, string(n, '.'));
        if(n / 2 + n % 2 < k){
            cout << "-1\n";
            continue;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if((i & 1) && (j & 1) && i == j && k){
                    cout << "R";
                    --k;
                }
                else cout << ".";
            }
            cout << "\n";
        }
    }
}