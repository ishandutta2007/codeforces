//  sathu
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
    int n; cin >> n;
    string str; cin >> str;
    char check = str[0];
    bool ch = false;
    for(int i=0; i<n; i++){
        if(str[i]!=check){
            ch = true;
        }
    }
    if(ch==false){
        cout << n-1;
    }
    else{
        int ans = 0;
        for(int i=0; i<n; i++){
            if(str[i]==str[i+1]){
                int k = i;
                i++;
                while(i<n && str[k]==str[i]){
                    //cout << i << sp << str[i] << ln;
                    ans++;
                    i++;
                }
                i--;
            }
        }
        cout << ans;
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