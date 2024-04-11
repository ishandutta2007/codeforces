#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
#include <stdio.h>
#include <ctype.h>
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}


void solve(){
    bool up = false;
    bool down = false;
    bool dig = false;
    bool al = false;
    int l;
    string s; cin >> s;
    l = s.size();
    for(int i=0; i<s.size(); i++){
        if(isupper(s[i])){
            up = true;
        }
        else if(islower(s[i])){
            down = true;
        }
        else if(isdigit(s[i])){
            al = true;
        }
    }
    if(up == true && down == true && al == true && l >= 5){
        cout << "Correct" << ln;
    }
    else {
        cout << "Too weak" << ln;
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