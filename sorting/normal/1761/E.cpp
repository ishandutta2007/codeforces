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

        vector<string> s(n);
        for(int i = 0; i < n; ++i)
            cin >> s[i];

        vector<int> ans;
        vector<int> vis(n, 0);

        function<void(int, int)> dfs = [&](int x, int col){
            vis[x] = col;
            for(int i = 0; i < n; ++i)
                if(!vis[i] && s[x][i] == '1'){
                    dfs(i, col);
                }
        };

        int col = 0;
        for(int i = 0; i < n; ++i)
            if(!vis[i]){
                ++col;
                dfs(i, col);
            }

        // for(int i = 0; i < n; ++i)
            // cout << vis[i] << " ";
        // cout << " - " << col << endl;

        if(col == 1){
            cout << "0\n";
            continue;
        }

        bool ok = true;
        for(int i = 0; i < n; ++i){
            int cnt_same = 0;
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                if(ok && vis[i] == vis[j] && s[i][j] == '0'){
                    col++;

                    int prev_col = vis[i];

                    function<void(int, int)> dfs2 = [&](int x, int col){
                        vis[x] = col;
                        bool visited_sth = false;
                        for(int i = 0; i < n; ++i)
                            if(vis[i] == prev_col && s[x][i] == '1'){
                                dfs2(i, col);
                                visited_sth = true;
                            }
                        if(!visited_sth && ok){
                            for(int i = 0; i < n; ++i)
                                if(ok && i != x && vis[i] == col && s[x][i] == '0'){
                                    ok = false;
                                    cout << "1\n";
                                    cout << x + 1 << "\n";
                                    break;
                                }
                            return;
                        }
                    };

                    dfs2(i, col);

                    if(ok){
                        ok = false;
                        cout << "1\n";
                        cout << i + 1 << "\n";
                    }

                    break;
                }
                if(vis[i] == vis[j])
                    ++cnt_same;
            }

            if(ok && cnt_same == 0){
                ok = false;
                cout << "1\n";
                cout << i + 1 << "\n";
                break;
            }
        }
        if(!ok)
            continue;

        if(col != 2){
            ans.push_back(1);
            for(int i = 1; i < n; ++i){
                if(vis[i] != vis[0]){
                    ans.push_back(i + 1);
                    break;
                }
            }
            cout << "2\n";
            cout << ans[0] << " " << ans[1] << "\n";
            continue;
        }

        int cnt[3]{};
        for(int i = 0; i < n; ++i)
            ++cnt[vis[i]];

        int t = 1;
        if(cnt[2] < cnt[1])
            t = 2;

        cout << cnt[t] << "\n";        
        for(int i = 0; i < n; ++i)
            if(vis[i] == t)
                cout << i + 1 << " ";
        cout << "\n";
    }
}