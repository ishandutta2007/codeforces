#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1000 + 3;

int n, k, ans, groups;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    int x = 1, ans = 0;
    while(x < n){
        x *= k;
        ++ans;
    }
    x /= k;

    cout << ans << "\n";
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j){
            int col = 1;
            int ti = i, tj = j;
            while(true){
                if(ti / k == tj / k){
                    cout << col << " ";
                    break;
                }
                ti /= k;
                tj /= k;
                ++col;
            }
        }
    cout << "\n";
}