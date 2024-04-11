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
        int k, n;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        int cnt = 0;
        for(int i = 0; i < n; ++i)
            cnt |= a[i];

        if(cnt)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}