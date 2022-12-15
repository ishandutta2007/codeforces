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
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        int t = 1;
        for(auto &[x, id]: v){
            cin >> x;
            id = t++;
        }
        sort(all(v));
        cout << v[0].second << " " << v.back().second << "\n";
    }
}