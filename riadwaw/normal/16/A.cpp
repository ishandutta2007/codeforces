#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
void solve(){
    int n,m;
    string s[111];
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>s[i];
        if(i && s[i][0]==s[i-1][0]){
            cout<<"NO";
            return;
        }
        for(int j=1;j<m;++j){
            if(s[i][j]!=s[i][0]){
                cout<<"NO";
                return;
            }
        }
    }
    cout<<"YES";
}