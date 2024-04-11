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

        pair<int, int> ans{-1, -1};
        vector<vector<int>> a(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> a[i][j];

        bool ok = true;
        for(int i = 0; i < n; ++i){
            vector<int> b(all(a[i]));
            sort(all(b));
            vector<int> diff;
            for(int j = 0; j < m; ++j)
                if(a[i][j] != b[j])
                    diff.push_back(j);
            if(diff.size() > 2){
                ok = false;
                break;
            }
            if(diff.size() == 2){
                if(ans.first != -1){
                    if(ans != pair{diff[0], diff[1]}){
                        ok = false;
                        break;
                    }
                }
                else
                    ans = {diff[0], diff[1]};
            }
        }

        if(ok){
            for(int i = 0; i < n; ++i){
                vector<int> b(all(a[i]));
                sort(all(b));
                vector<int> diff;
                for(int j = 0; j < m; ++j)
                    if(a[i][j] != b[j])
                        diff.push_back(j);
                if(diff.empty()){
                    if(a[i][ans.first] != a[i][ans.second]){
                        ok = false;
                        break;
                    }
                }
            }
        }

        if(!ok){
            cout << "-1\n";
        }
        else{
            if(ans.first == -1){
                cout << "1 1\n";
            }
            else{
                ++ans.first, ++ans.second;
                cout << ans.first << " " << ans.second << "\n";
            }
        }
    }
}