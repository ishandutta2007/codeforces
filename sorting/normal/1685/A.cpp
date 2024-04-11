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

        if(n & 1){
            cout << "NO\n";
            continue;
        }

        sort(all(a));

        bool ok = true;
        for(int i = 1; i < n / 2; ++i)
            if(a[i] == a[i + n / 2 - 1]){
                ok = false;
                break;
            }

        if(!ok){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(int i = 0; i < n / 2; ++i){
            cout << a[i] << " ";
            cout << a[i + n / 2] << " ";
        }
        cout << "\n";
    }
}