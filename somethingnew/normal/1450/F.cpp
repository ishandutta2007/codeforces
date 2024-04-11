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
    vector<int> lst;
    vector<vector<int>> grp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(lst.empty()){
            lst.push_back(a);
            continue;
        }
        if(lst.back() == a){
            grp.push_back(lst);
            lst = {};
            lst.push_back(a);
        }else{
            lst.push_back(a);
        }
    }
    grp.push_back(lst);
    vector<int> cnt(n + 1, 0);
    for (auto i : grp) {
        //cout << endl;
        //cout << "IFB " << i.front() << ' ' << i.back() << endl;
        cnt[i.front()]++;
        cnt[i.back()]++;
    }
    int ans = (int)grp.size() - 1;
    //cout << "ans: " << ans << '\n';
    int mxp = 0;
    for (int i = 0; i <= n; ++i) {
        if(cnt[mxp] < cnt[i])
            mxp = i;
    }
    //cout << "mxp: " << mxp << " " << cnt[mxp] << endl;
    int val = max(0, cnt[mxp] - (int)grp.size() - 1);
    int v2 = 0;
    for(auto i : grp){
        for (int j = 1; j < i.size(); ++j) {
            if(i[j] != mxp and i[j-1] != mxp)
                v2++;
        }
    }
    if(v2 < val){
        cout << "-1\n";
        return;
    }
    cout << val + ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}