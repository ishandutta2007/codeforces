#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1509][1509];
int b[1509][1509];
int f[1509];
int n, m;
int deg[1509];
vector<int> ans;
vector<int> v[1509];
queue<int> q;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> A, B;
    for(int i = 1; i <= n; i++){
        A.push_back(i);
        B.push_back(i);
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> b[i][j];
        }
    }
    for(int j = 1; j <= m; j++){
        for(int i = 2; i <= n; i++){
            if(b[i][j] < b[i-1][j]){
                deg[j]++;
                v[i].push_back(j);
            }
        }
        if(deg[j] == 0) q.push(j);
    }
    while(q.size()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int i = 2; i <= n; i++){
            if(f[i] == 0 && b[i][x] > b[i-1][x]){
                f[i] = 1;
                for(int j : v[i]){
                    deg[j]--;
                    if(deg[j] == 0) q.push(j);
                }
            }
        }
    }
    sort(A.begin(), A.end(), [] (int i, int j){
            for(int k : ans){
                if(a[i][k] < a[j][k]) return true;
                if(a[i][k] > a[j][k]) return false;
            }
            return (i < j);
         });
     for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(a[A[i]][j] != b[B[i]][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] <<" ";
    cout<<endl;
}