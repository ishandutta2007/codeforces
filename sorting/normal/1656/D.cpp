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
        ll n;
        cin >> n;
        ll pwr2 = 1, m = n;
        while(m % 2 == 0){
            m /= 2;
            pwr2 *= 2;
        }

        if(m == 1){
            cout << "-1\n";
            continue;
        }

        if(pwr2 * 2 >= m + 1)
            cout << m << "\n";
        else
            cout << pwr2 * 2 << "\n";
    }
}