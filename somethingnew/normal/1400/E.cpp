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
int solve(vector<int> lst){
    int n = lst.size();
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int ans1 = n;
    vector<int> nw;
    int mn = lst[0];
    for (int i = 0; i < n; ++i) {
        mn = min(mn, lst[i]);
    }
    int ans2 = mn;
    for (int i = 0; i < n; ++i) {
        lst[i] -= mn;
        if(lst[i] == 0){
            ans2 += solve(nw);
            nw.clear();
        } else
            nw.push_back(lst[i]);
    }
    ans2 += solve(nw);
    return min(ans1,ans2);
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    vector<int> lst(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }
    vector<int> nw;
    for (int i = 0; i < n; ++i) {
        if(lst[i] == 0){
            ans += solve(nw);
            nw.clear();
        } else
            nw.push_back(lst[i]);
    }
    ans += solve(nw);
    cout << ans << endl;
}