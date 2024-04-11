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
        string s; cin >> s;
        char a = 'a';
        string b = "";
        char temp = 'z';
        int ind = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]<temp){
                temp = s[i];
                ind = i;
            }
        }
        a = temp;
        b = s.substr(0, ind) + s.substr(ind+1, s.length()-ind);
        cout << a << sp << b << ln;
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