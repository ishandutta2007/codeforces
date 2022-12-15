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
        int h, w;
        cin >> h >> w;

        vector<vector<bool>> a(h, vector<bool>(w, false));
        a[0][0] = 1;
        a[h - 1][w - 1] = 1;
        a[0][w - 1] = 1;
        a[h - 1][0] = 1;

        for(int i = 2; i < w - 2; i += 2)
            a[0][i] = a[h - 1][i] = 1;
        for(int i = 2; i < h - 2; i += 2)
            a[i][0] = a[i][w - 1] = 1;

        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j)
                cout << a[i][j] << "";
            cout << "\n";
        }
    }
}