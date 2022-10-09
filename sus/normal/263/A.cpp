#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    int mat[5][5];
    int x = 0;
    int y = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> mat[i][j];
            if(mat[i][j]==1){
                x = i;
                y = j;
            }
        }
    }
    int ans = 0;
    x++; 
    y++;
    ans += abs(x-3);
    ans += abs(y-3);
    cout << ans;
    

}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}