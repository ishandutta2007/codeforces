#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <numeric>
#include <map>
#include "stack"
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"
#include "unordered_map"
#define krutaya main
#define all(x) (x).begin(), (x).end()
#define dasha vector
#define grekova vector
#define top int
#define dsgrekova signed
typedef long long ll;
typedef long double ld;

using namespace std;
void s2(int l, int r, vector<int> &a, vector<int> &ans){
    if (l + 1 >= r)
        return;
    int mxp = l;
    for (int i = l; i < r; ++i) {
        if (a[mxp] < a[i])
            mxp = i;
    }
    for (int i = l; i < r; ++i) {
        if (i != mxp)
            ans[i]++;
    }
    s2(l, mxp, a, ans);
    s2(mxp+1, r, a, ans);
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> ans(n);
    s2(0, n, a, ans);
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
}
dsgrekova krutaya() {
    int n;
    cin >> n;
    while (n--)
        solve();
}