#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct str{
    int a, b, c, d, e, f;
};

int a[102][102];

void change(int r0, int c0, int u, int v, vector<str> &ans){
    int b[6];
    int c = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(i == u && j == v) continue;
            b[c] = r0 + i; b[c + 1] = c0 + j;
            c += 2;
        }
    }
    ans.push_back(str{b[0] + 1, b[1] + 1, b[2] + 1, b[3] + 1, b[4] + 1, b[5] + 1});
    for(int k = 0; k < 3; k++){
        a[b[k * 2]][b[k * 2 + 1]] = 1 - a[b[k * 2]][b[k * 2 + 1]];
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s[102];
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) a[i][j] = s[i][j] - '0';
        }
        vector<str> ans;
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 1; j++){
                if(a[i][j] == 0){
                    if(a[i][j + 1] == 1) change(i, j, 0, 0, ans);
                }
                else{
                    if(a[i][j + 1] == 1) change(i, j, 1, 0, ans);
                    else change(i, j, 0, 1, ans);
                }
            }
        }
        for(int j = 0; j < m - 2; j++){
            if(a[n - 2][j] == 0){
                if(a[n - 1][j] == 1) change(n - 2, j, 0, 0, ans);
            }
            else{
                if(a[n - 1][j] == 1) change(n - 2, j, 0, 1, ans);
                else change(n - 2, j, 1, 0, ans);
            }
        }
        for(int k = 0; k < 4; k++){
        out_loop:
            int t = 0;
            for(int u = 0; u < 2; u++){
                for(int v = 0; v < 2; v++){
                    t += a[n - 2 + u][m - 2 + v];
                }
            }
            if(t == 0) break;
            if(t == 1 || t == 3){
                for(int u = 0; u < 2; u++){
                    for(int v = 0; v < 2; v++){
                        if(a[n - 2 + u][m - 2 + v] == 0){
                            change(n - 2, m - 2, u, v, ans);
                            goto out_loop;
                        }
                    }
                }
            }
            else{
                for(int u = 0; u < 2; u++){
                    for(int v = 0; v < 2; v++){
                        if(a[n - 2 + u][m - 2 + v] == 1){
                            change(n - 2, m - 2, u, v, ans);
                            goto out_loop;
                        }
                    }
                }
            }
        }
        cout << (int)ans.size() << endl;
        for(int i = 0; i < (int)ans.size(); i++){
            cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << " " << 
                ans[i].d << " " << ans[i].e << " " << ans[i].f << endl;
        }
    }
}