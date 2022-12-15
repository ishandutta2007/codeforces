#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

ll get_number(int n, int b, vector<int> x){
    ll ans = 0, curr = 1;
    for(int i = n - 1; i >= 0; --i){
        ans += curr * x[i];
        curr *= b;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, bx;
    cin >> n >> bx;
    vector<int> x(n);
    for(int i = 0; i < n; ++i)
        cin >> x[i];

    int m, by;
    cin >> m >> by;
    vector<int> y(m);
    for(int i = 0; i < m; ++i)
        cin >> y[i];

    ll numx = get_number(n, bx, x);
    ll numy = get_number(m, by, y);

    if(numx == numy)
        cout << "=\n";
    else if(numx < numy)
        cout << "<\n";
    else
        cout << ">\n";
}