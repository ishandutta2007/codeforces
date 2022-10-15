#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > A(m);
    for(int i = 0; i < m; ++i){
        cin >> A[i].first >> A[i].second;
    }
    ll mx = 0;
    for(int i = 1; i < m; ++i){
        if(abs(A[i].second - A[i - 1].second) > A[i].first - A[i - 1].first){
            cout << "IMPOSSIBLE";
            return 0;
        }else{
            ll res = A[i].first - A[i - 1].first;
            res -= abs(A[i].second - A[i - 1].second);
            res /= 2;
            res += max(A[i].second, A[i - 1].second);
            mx = max(mx, res);
        }
    }
    mx = max(mx, A[0].first + A[0].second - 1);
    mx = max(mx, n - A[m - 1].first + A[m - 1].second);
    cout << mx;
    return 0;
}