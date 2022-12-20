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
        int x, y;
        cin >> x >> y;

        if(x == y){
            cout << x << "\n";
            continue;
        }
        if(x > y){
            cout << x + y << "\n";
            continue;
        }

        int rem = y % x;
        cout << y - (rem / 2) << "\n";
    }
}