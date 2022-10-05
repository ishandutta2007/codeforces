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
#define all(x) (x).begin(), (x).end()

using namespace std;
void solve(){
    int n;
    cin >> n;
    string a = "2020", s;
    cin >> s;
    int pref = 0, suff = 0;
    while(pref < 4 and s[pref] == a[pref])
        pref++;
    while(suff < 4 and a[3-suff] == s[n-1-suff])
        suff++;
    if(pref + suff >= 4)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}