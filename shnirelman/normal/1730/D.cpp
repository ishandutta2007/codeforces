#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    map<pair<int, int>, int> mp;
    set<pair<int, int>> st;
    int cnt_odd_simmetric = 0;
    int cnt_odd = 0;
    for(int i = 0; i < n; i++){
        pair<int, int> p = {s1[i], s2[n - i - 1]};
        if(p.first > p.second){
            p = {p.second, p.first};
        }
        if(st.count(p) != 0){
            mp[p]++;
            if(mp[p] % 2 == 1){
                cnt_odd++;
                if(p.first == p.second){
                    cnt_odd_simmetric++;
                }
            }
            else{
                cnt_odd--;
                if(p.first == p.second){
                    cnt_odd_simmetric--;
                }
            }
        }
        else{
            st.insert(p);
            mp[p] = 1;
            cnt_odd++;
            if(p.first == p.second){
                cnt_odd_simmetric++;
            }
        }
    }
    if(n % 2 == cnt_odd_simmetric && cnt_odd == cnt_odd_simmetric){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}