#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 3;

int n, k[N], x[N];
int mx[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fill(mx, mx + N, -1);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> k[i];
        if(x[i] <= mx[k[i]]) continue;
        if(x[i] > mx[k[i]] + 1){
            cout << "NO\n";
            return 0;
        }
        mx[k[i]] = x[i];
    }
    cout << "YES\n";
}