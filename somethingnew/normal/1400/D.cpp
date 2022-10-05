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
    int n;
    cin >> n;
    vector<int> lst(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }
    long long res = 0;
    for (int a = 0; a < n; ++a) {
        long long resnow = 0;
        vector<int> m1(n+1,0);
        vector<int> m1andm2(n+1,0);
        vector<int> m2(n+1,0);
        for (int i = a + 1; i < n; ++i) {
            m2[lst[i]] += 1;
        }
        for (int c = a + 1; c < n; ++c) {
            m2[lst[c]] -= 1;
            if(m2[lst[c]] * m1[lst[c]] < m1andm2[lst[c]]){
                resnow += m2[lst[c]] * m1[lst[c]] - m1andm2[lst[c]];
                m1andm2[lst[c]] = m2[lst[c]] * m1[lst[c]];
            }

            if(lst[c] == lst[a]){
                res += resnow;
            }


            m1[lst[c]] += 1;
            if(m2[lst[c]] * m1[lst[c]] > m1andm2[lst[c]]){
                resnow += m2[lst[c]] * m1[lst[c]] - m1andm2[lst[c]];
                m1andm2[lst[c]] = m2[lst[c]] * m1[lst[c]];
            }
        }
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