#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'

bool isP(string &s, int i , int j){
    if(i >= j) {
        return true;
    }
    return s[i]==s[j]&&isP(s,i+1,j-1);
}
 
void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int k; cin >> k;
        string s; cin >> s;
        if(isP(s,0,s.size()-1)||k==0){
            cout<<1<<ln;
        } 
        else cout<<2<<endl;
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