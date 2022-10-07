#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A[1009][1009],B[1009][1009],f[1009][1009],a[1009][1009];
ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};
main(){
    ios_base::sync_with_stdio(false);
    ll n, m,t;
    cin >> n >> m >> t;
    for(ll i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(ll j = 1; j <= m; j++){
            a[i][j] = s[j-1] - '0';
        }
    }
    queue<pair<ll,ll> > q;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            f[i][j] = 1;
        }
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            A[i][j] = 1e9;
            for(ll d = 0; d < 4; d++){
                ll nx = i + dx[d];
                ll ny = j + dy[d];
                if(f[nx][ny] && a[i][j] == a[nx][ny]){
                    q.push({i,j});
                    A[i][j] = 1;
                    break;
                }
            }
        }
    }
    while(q.size()){
        ll x = q.front().first, y = q.front().second;
        q.pop();
        for(ll i = 0; i < 4; i++){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(A[nx][ny] == 1e9 && f[nx][ny]){
                A[nx][ny] = A[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    while(t--){
        ll i,j,p;
        cin>>i>>j>>p;
        ll x = A[i][j];
        if(x == 1e9 || x > p){
            cout<<a[i][j]<<endl;
        }
        else{
            if((p - x) % 2 == 0){
                cout<<1-a[i][j]<<endl;
            }
            else cout<<a[i][j]<<endl;
        }
    }

}
/*

*/