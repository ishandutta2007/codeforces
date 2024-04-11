#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n';
#define no  cout << "NO" << '\n';
#define sp " "
#define ln '\n'

bool check(int arr[], int arr2[], int n){
    for(int i=0; i<n; i++){
            if(arr2[i]!=arr[i]){
                return false;
            }
        }
        return true;
}
 
void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        int arr2[n];
        for(int i=0; i<n; i++) arr2[i]=arr[i];
        sort(arr2, arr2+n);
        bool e = check(arr, arr2, n);
        if(e) no
        else yes
    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}