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
        string e; cin >> e;
        int acount = 0;
        int bcount = 0; 
        int ccount = 0;
        for(int i=0; i<e.size(); i++){
            if(e[i]=='A') acount++;
            else if(e[i]=='B') bcount++;
            else ccount++;
        }
        
        bcount-=acount;
        if(bcount==ccount) yes;
        else{
            no;
        }
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