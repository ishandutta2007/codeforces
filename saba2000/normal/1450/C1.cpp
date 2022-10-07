#include<bits/stdc++.h>
using namespace std;
int a[309][309];
char F[3] = {'.','X','O'};
void solve(){
    int n;
    cin >> n;
    int tot = 0;
    vector<pair<int,int> > V[3][3];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            if(c == 'X') a[i][j] = 1; else
            if(c == 'O') a[i][j] = 2; else
                a[i][j] = 0;
            if(a[i][j]) tot++;
            V[a[i][j]][(i+j)%3].push_back({i,j});
        }
    }
    tot/=3;
    for(int i = 1; i <= 6; i++){
        int cur =0;
        for(int j = 0; j < 3; j++){
            if((1<<j) & i) cur += V[1][j].size();
                else cur += V[2][j].size();
        }
        if(cur <= tot){
            for(int j = 0; j < 3; j++){
                int hm = 2;
                if((1<<j) & i) hm = 1;
                for(auto S : V[hm][j]){
                    a[S.first][S.second] = 3 - a[S.first][S.second];
                }
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    cout<<F[a[i][j]];

                }
                cout<<endl;
            }
            return;
        }
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        solve();

    }



}