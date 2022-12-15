#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<string> s(n);
        for(int i = 0; i < n; ++i)
            cin >> s[i];

        int t = -1;
        bool ok = true;
        for(int i = 0; i < n && ok; ++i)
            for(int j = 0; j < m && ok; ++j){
                if(s[i][j] != '.'){
                    int cand = 0;
                    if(s[i][j] == 'R')
                        cand = (i + j) & 1;
                    else
                        cand = !((i + j) & 1);
                    if(t != -1 && t != cand){
                        ok = false;
                        break;
                    }
                    t = cand;
                }
            }

        if(!ok){
            cout << "NO\n";
            continue;
        }

        if(t == -1) t = 0;
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(((i + j) & 1) == t)
                    cout <<  "R";
                else
                    cout << "W";
            }
            cout << "\n";
        }
    }
}