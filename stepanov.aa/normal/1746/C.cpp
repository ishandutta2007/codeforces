#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define flt double
#define all(a) a.begin(), a.end()


int n;
vector<int> a;
set<int> sa;


int32_t main(){
    if(1){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        sa.clear();
        for(int i = 0; i < n; i += 1){
            cin >> a[i];
        }
        vector<int> rs(n + 1, -1);
        for(int i = 0; i + 1 < n; i += 1){
            rs[a[i]] = i + 1;
        }
        for(int i = 1; i <= n; i += 1){
            if(rs[i] == -1){
                rs[i] = 0;
            }
            cout << rs[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}