#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll c, d;
        cin >> c >> d;
        if(abs(c - d) & 1){
            cout << "-1\n";
            continue;
        }
        if(c > d) swap(c, d);
        if(c == d){
            if(c == 0) cout << "0\n";
            else cout << "1\n";
            continue;
        }
        if(c + d == 0) cout << "1\n";
        else{
            cout << "2\n";
        }
    }
}