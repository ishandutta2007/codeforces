#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;

int n, a[N];

int nxt(int x){
    if(x == 1) return 1;
    return 2 * x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    for(int i = 0; i < n - 1; ++i)
        if(a[i] != a[i + 1]){
            if(nxt(a[i]) > a[i + 1]){
                cout << "YES\n";
                return 0;
            }
        }
    cout << "NO\n";
}