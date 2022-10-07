#include<bits/stdc++.h>
using namespace std;
int A[109][109];
vector<vector<int> > ans;
void add(int a, int b, int c, int d, int e, int f){
    ans.push_back({a,b,c,d,e,f});
    A[a][b]^=1;
    A[c][d]^=1;
    A[e][f]^=1;
}
bool check(int a, int b, int c, int d, int e, int f){
    int u = A[a][b]+ A[c][d] + A[e][f];
    return u == 1 || u == 3;
}
void solve1(int i, int j){

    while(A[i][j]+A[i+1][j]+A[i][j+1]+A[i+1][j+1]){

        if(check(i,j,i,j+1,i+1,j+1)) {add(i,j,i,j+1,i+1,j+1); continue;}//i+1 j
        if(check(i+1,j,i,j+1,i+1,j+1) ){add(i+1,j,i,j+1,i+1,j+1);continue;} //i j
        if(check(i,j,i,j+1,i+1,j)) {add(i,j,i,j+1,i+1,j);continue;} //i+1 j+1
        if(check(i,j,i+1,j,i+1,j+1) ){add(i,j,i+1,j,i+1,j+1);continue;} //i j+1
        
    }

}
void solve(){
    int n,m;
    cin>>n>>m;
    ans.clear();
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c=='1') A[i][j] = 1;
            else A[i][j] = 0;
        }
    }
    if(n % 2 == 1 || m % 2 == 1){
        if(A[n][m]){
            add(n,m,n-1,m,n,m-1);
        }
    }
    if(n % 2 == 1){
        for(int j = 1; j < m; j++){
            if(A[n][j]){
                if(j == 1){
                    add(n,j,n-1,j,n-1,j+1);
                }
                else
                add(n,j,n-1,j,n-1,j-1);
            }
        }
    }
    if(m % 2 == 1){
        for(int i = 1; i < n; i++){
            if(A[i][m]){
                if(i == 1){
                    add(i,m,i,m-1,i+1,m-1);
                }
                else add(i,m,i,m-1,i-1,m-1);
            }
        }
    }
    for(int i = 1; i < n; i+=2){
        for(int j = 1; j< m; j+=2){
            solve1(i,j);
        }
    }
    cout<<ans.size()<<endl;
    for(int i = 0 ;i  < ans.size(); i++){
        for(int x : ans[i])
            cout<<x<<" ";
        cout<<endl;
    }


}
main(){
    int t;
    cin>>t;
    while(t--){
        solve();

    }


}