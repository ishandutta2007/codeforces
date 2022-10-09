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
    for(int i=0; i<t; i++){
        int n; cin >> n;
        int count = 0;
        int curr = 0;
        int counter = 1;
        while(count<n){
            if(counter%3!=0 && counter%10!=3){
                curr = counter;
                count++;
            }
            counter++;
        }
        cout << curr << ln;
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