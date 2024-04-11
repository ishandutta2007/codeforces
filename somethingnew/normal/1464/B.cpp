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
#define int long long
using namespace std;
void solve(){
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    if(x > y){
        swap(x, y);
        for(auto & i : s)
            if(i == '0')
                i = '1';
            else if(i == '1')
                i = '0';
    }
    int pref0 = 0, pref1 = 0, suff0 = 0, suff1 = 0;
    for (auto i : s) {
        if(i == '1')
            suff1 += 1;
        if(i == '0')
            suff0 += 1;
    }
    //cout << suff0 << ' ' << suff1 << endl;
    int res = 0;
    vector<pair<int, int>> vopr;
    for (auto i : s) {
        if(i == '1'){
            suff1--;
            pref1++;
            res += suff0 * y;
        }
        if(i == '0'){
            suff0--;
            pref0++;
            res += suff1 * x;
        }
        if(i == '?'){
            vopr.push_back({pref1 * y + suff1 * x, pref0 * x + suff0 * y});
        }
    }
    //cout << res;
    for(auto i : vopr){
        res += i.first;
    }
    //cout << res;
    int ans = res;
    int prefvopr = vopr.size();
    int suffvopr = 0;
    while(!vopr.empty()){
        res -= vopr.back().first;
        res += vopr.back().second;
        vopr.pop_back();
        prefvopr -= 1;
        suffvopr += 1;
        ans = min(ans, res + prefvopr * suffvopr * x);
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    solve();
}