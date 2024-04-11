#include <iostream>
#include <vector>
using namespace std;

int a[100005], b[100005], c[100005];
int ans[100005];
vector<int> v[100005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i <= n; i++) v[i].clear();
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            b[i]--;
        }
        for(int i = 0; i < m; i++){
            cin >> c[i];
            c[i]--;
        }
        int l;
        for(l = 0; l < n; l++){
            if(a[l] != b[l] && b[l] == c[m - 1]) break;
        }
        if(l == n){
            for(l = 0; l < n; l++){
                if(b[l] == c[m - 1]) break;
            }
        }
        if(l == n){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                v[b[i]].push_back(i);
            }
        }
        for(int i = 0; i < m; i++){
            if((int)v[c[i]].size()){
                ans[i] = v[c[i]].back();
                a[ans[i]] = c[i];
                v[c[i]].pop_back();
            }
            else{
                ans[i] = l;
            }
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]) f = false;
        }
        if(f){
            cout << "YES" << endl;
            for(int i = 0; i < m; i++) cout << ans[i] + 1 << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
}