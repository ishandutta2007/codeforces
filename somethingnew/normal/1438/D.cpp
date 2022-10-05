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
void xr(int &a, int &b, int &c){
    int t = (a ^ b) ^ c;
    a = t;
    b = t;
    c = t;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(auto &i : a)
        cin >> i;
    vector<int> ans;
    int i;
    for (i = 0; i + 2 < n; i += 2) {
        xr(a[i], a[i+1], a[i+2]);
        ans.push_back(i + 1);
    }
    i -= 2;
    for (; i >= 0; i -= 2) {
        xr(a[i], a[i+1], a[i+2]);
        ans.push_back(i + 1);
    }
    for (i = 0; i < n; ++i) {
        if(a[i] != a[0]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    cout << ans.size() << endl;
    for(auto j : ans)
        cout << j << ' ' << j + 1 << ' ' << j + 2 << '\n';
}