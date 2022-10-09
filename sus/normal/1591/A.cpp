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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int h=1;
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                if(i!=0 && arr[i-1]==0){
                    h=-1;
                    break;
                }
            }
            if(arr[i]==1){
                if(i!=0 && arr[i-1]==1){
                    h+=5;
                }
                else{
                    h++;
                }
            }
        }
        cout << h << ln;

    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}