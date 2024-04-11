#include <bits/stdc++.h>

using namespace std;
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
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        for(int i = 0; i < n; ++i)
            cin >> v[i];
            
        int sum = 0;
        vector<int> ans, new_v;
        for(int i = 0; i < v.size(); ++i){
            if(sum + v[i] == x) new_v.push_back(v[i]);
            else{
                sum += v[i];
                ans.push_back(v[i]);
            }
        }

        for(int i = 0; i < new_v.size(); ++i){
            if(sum + new_v[i] != x){
                sum += new_v[i];
                ans.push_back(new_v[i]);
            }
        }

        if(ans.size() == n){
            cout << "YES\n";
            for(int i = 0; i < n; ++i)
                cout << ans[i] << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
}