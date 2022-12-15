#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    static string s[103];
    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; ++i)
            cin >> s[i];
    
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(s[i][j] == '1'){
                    int x, y;
                    if(i) x = i - 1;
                    else x = i;
                    if(j) y = j - 1;
                    else y = j;

                    vector<array<int, 2>> c;
                    for(int i2 = x; i2 <= x + 1; ++i2){
                        for(int j2 = y; j2 <= y + 1; ++j2){
                            if(i2 == i && j2 == j) continue;
                            c.push_back({i2, j2});
                        }
                    }

                    ans.push_back({i, j, c[0][0], c[0][1], c[1][0], c[1][1]});
                    ans.push_back({i, j, c[0][0], c[0][1], c[2][0], c[2][1]});
                    ans.push_back({i, j, c[2][0], c[2][1], c[1][0], c[1][1]});
                }
            }
        }

        cout << ans.size() << "\n";
        for(auto v: ans){
            for(int i = 0; i < v.size(); ++i)
                cout << v[i] + 1 << " ";
            cout << "\n";
        }
    }
}