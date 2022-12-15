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
        int n, m;
        cin >> n >> m;

        vector<array<int, 3>> r(m);
        for(int i = 0; i < m; ++i)
            cin >> r[i][0] >> r[i][1] >> r[i][2];

        vector<int> v;
        for(int i = 0; i < m; ++i)
            v.push_back(r[i][1]);
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());

        int ptr = 1;
        for(int i = 0; i < m; ++i){
            if(v[i] != ptr) break;
            ++ptr;
        }

        for(int i = 1; i <= n; ++i){
            if(i != ptr) cout << ptr << " " << i << "\n";
        }
    }
}