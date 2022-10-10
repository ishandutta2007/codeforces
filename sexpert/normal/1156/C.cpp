#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, z;
 
bool check(int m, vector<int> &a) {
    for(int i = 0; i < m; i++) {
        //cout << m << " " << a[n - m + i] << " " << a[i] << endl;
        if(a[n - m + i] - a[i] < z) return false;
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> z;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int lo = 0, hi = n/2;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(check(mi, a)) lo = mi;
        else hi = mi - 1;
    }
    cout << lo << endl;
}