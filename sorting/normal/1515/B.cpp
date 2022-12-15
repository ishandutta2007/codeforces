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

        if(n & 1){
            cout << "NO\n";
            continue;
        }

        int t = sqrt(n >> 1);
        if(t * t > (n >> 1)) --t;
        if(t * t < (n >> 1)) ++t;
        if(t * t == (n >> 1)){
            cout << "YES\n";
            continue;
        }
        
        if(n % 4 != 0){
            cout << "NO\n";
            continue;
        }

        t = sqrt(n >> 2);
        if(t * t > (n >> 2)) --t;
        if(t * t < (n >> 2)) --t;
        if(t * t == (n >> 2)){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}