#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<vector<ull>> c(n, vector<ull>(m, (ull)0));
        map<ull, pair<int, int>> mp;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                cin >> c[i][j];
            ull sum = c[i][0];
            for(int j = 1; j < m; ++j){
                c[i][j] += c[i][j - 1];
                sum += c[i][j];
            }
            mp[sum].first += 1;
            mp[sum].second = i + 1;
        }

        ull sum1, sum2;
        for(auto [sum, p]: mp){
            if(p.first == 1)
                sum1 = sum;
            else
                sum2 = sum;
        }

        for(auto [sum, p]: mp){
            if(p.first == 1){
                cout << p.second << " " << sum2 - sum1 << "\n";
            }
        }
    }
}