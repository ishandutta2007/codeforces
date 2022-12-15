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

        vector<int> a(n), b(n), t(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i] >> b[i];
        }
        for(int i = 0; i < n; ++i)
            cin >> t[i];

        int curr = a[0] + t[0];
        for(int i = 0; i < n - 1; ++i){
            curr = max(curr + (b[i] - a[i] + 1) / 2, b[i]);
            curr += a[i + 1] - b[i];
            curr += t[i + 1];
        }
        cout << curr << "\n";
    }
}