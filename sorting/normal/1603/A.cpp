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

        bool ans = true;
        for(int i = 0; i < n; ++i){
            bool ok = false;
            for(int j = 2; j <= i + 2; ++j){
                if(a[i] % j != 0){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }
}