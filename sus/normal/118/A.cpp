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
    string n; cin >> n;
    queue<char> fin;
    
    for(int i=0; i<n.length(); i++){
        n[i]=tolower(n[i]);
        if(n[i]!='a' && n[i]!='o' && n[i]!='i' && n[i]!='e' && n[i]!='u' && n[i]!='y'){
            fin.push(n[i]);
            //cout << n[i] << ln;
        }
    }
    
    while(!fin.empty()){
        cout << ".";
        cout << fin.front();
        fin.pop();
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