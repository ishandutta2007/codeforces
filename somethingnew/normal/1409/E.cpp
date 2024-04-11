#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int Stepa;
    for (int i = 0; i < n; ++i) {
        cin >> Stepa;
    }
    sort(x.begin(), x.end());
    vector<pair<int,int>> platf(n, {0,0});
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while(r != n and x[r] <= x[l] + k){
            r++;
        }
        platf[l] = {r - l, r};
    }
    vector<int> maxzn(n+1, 0);
    int res = 0;
    for (int i = n-1; i >= 0; --i) {
        res = max(res, platf[i].first + maxzn[platf[i].second]);
        maxzn[i] = max(maxzn[i + 1], platf[i].first);
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}