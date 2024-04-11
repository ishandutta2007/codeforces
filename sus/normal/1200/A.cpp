#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    int n; cin >> n;
    int rooms[10];
    for(int i=0; i<10; i++){
        rooms[i] = 0;
    }
    string s; cin >> s;
    for(int i=0; i<n; i++){
        if(s[i]=='L'){
            int r = 0;
            while(rooms[r]!=0){
                r++;
            }
            rooms[r] = 1;
            
        }
        else if(s[i]=='R'){
            int r = 9;
            while(rooms[r]!=0){
                r--;
            }
            rooms[r] = 1;
        }
        else{
            int e = s[i] - '0';
            rooms[e] = 0;
        }
    }
    for(int i=0; i<10; i++){
        cout << rooms[i];
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