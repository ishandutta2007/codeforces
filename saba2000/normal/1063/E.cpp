#include<bits/stdc++.h>
using namespace std;
int f[1009];
int a[1009];
int p[1009];
int r[1009];
char ans[1009][1009];
int l[1009];
void dfs(int x){
    f[x] = 1;
    if(f[a[x]] == 0) dfs(a[x]);
}
main(){
    int n;
    cin >> n;
    for(int i=  1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            ans[i][j] = '.';
    }
    bool fl = false;
    for(int i= 1; i <= n; i++){
        cin >> a[i];
        r[a[i]] = i;
        if(a[i] != i) fl = 1;
    }
    vector<int> v;
    if(fl){
        for(int i = 1; i <= n; i++){
            if(f[i] == 0){
                v.push_back(i);
                ans[n][i] = '/';
                dfs(i);
            }
        }
        for(int i = 1; i <= n; i++)
            p[i] = i;
        p[v[0]] = 0;
        for(int i = v.size() - 1; i > 0; i--){
            p[v[i]] = v[i - 1];
        }
        for(int i = 1; i <= n; i++)
            l[p[i]] = i;
        int x = v[0];
        for(int i = n - 1; i >= 1; i--){
            int y = l[r[x]];
            if(y < x){
                ans[i][y] = '/';
                ans[i][x] = '/';
            }
            else{
                ans[i][y] = 92;
                ans[i][x] = 92;
            }
            x = y;
        }
    }
    if(fl) cout<<n-1<<endl;
    else cout<<n<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ans[i][j];
        }
        cout<<endl;
    }

}