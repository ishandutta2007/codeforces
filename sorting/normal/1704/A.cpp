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
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        bool ok = false;
        for(int i = 0; i <= n - m; ++i)
            ok |= a[i] == b[0];
        

        for(int i = 1; i < m; ++i)
            ok &= b[i] == a[i + (n - m)];

        if(!ok){
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
    }
}