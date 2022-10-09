#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    
    
        int n, k; cin >> n >> k;
        pair<int, int> a[n/2];
        int l = 0;
        for(int i=1; i<=n; i+=2){
            a[l].first = i;
            a[l].second = i+1;
            l++;
        }
        for(int i=0; i<n/2; i++){
            if((((a[i].first + k)*a[i].second) % 4 != 0) && (((a[i].second + k)*a[i].first) % 4 != 0)){
                no;
                return;
            }
            else{
                if(((a[i].first + k)*a[i].second)%4!=0){
                    int r = a[i].first;
                    a[i].first = a[i].second;
                    a[i].second = r;
                }
            }
        }
        yes;
        for(int i=0; i<n/2; i++){
            cout << a[i].first << sp << a[i].second << ln;
        }
    
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}