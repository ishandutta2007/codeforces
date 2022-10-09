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
        int num[n];
        string s;
        cin >> s;
        for(int i=0; i<n; i++){
            num[i]=(int)(s[i]-'0');
        }
        int ans = 0;
        int temp=0;
        for(int i=0; i<n; i++){
            if(num[i]!=0){
                ans++;
            }
            
        }
        for(int i=0; i<n; i++){
            temp+=num[i];
        }
        if(num[n-1]!=0){
            temp--;
        }
        cout << ans+temp<< ln;

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