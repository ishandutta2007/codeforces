#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

vector<int> hash_function(string s){
    int n = s.length();
    int p = 1;
    vector<int> hs(n);
    hs[0] = s[0] - 'a' + 1;
    for(int i = 1; i < n; ++i){
        p *= 47;
        hs[i] = hs[i-1] + (s[i] - 'a' + 1) * p;
    }
    return hs;
}

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    pair<int, int> qwer;
    vector<pair<int, int>> a;
    vector<int> res(200001, 0);
    for(int i = 0; i < n; ++i){
        cin >> qwer.first;
        qwer.second = 1;
        a.push_back(qwer);
        cin >> qwer.first;
        ++qwer.first;
        qwer.second = -1;
        a.push_back(qwer);
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int yk = 0;
    for(int i = 1; i < 200001; ++i){
        while(yk < a.size() && i == a[yk].first){
            cnt += a[yk].second;
            ++yk;
        }
        if(cnt >= k){
            res[i] = res[i-1] + 1;
        }else{
            res[i] = res[i-1];
        }
    }
    for(int i = 0, l, r; i < q; ++i){
        cin >> l >> r;
        cout << res[r] - res[l-1] << endl;
    }
    return 0;
}