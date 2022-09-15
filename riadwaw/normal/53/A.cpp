#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<li,li> pli;
void solve();
int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}
void solve(){
    string s,t[111];
    cin>>s;
    int n,l=s.length();
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>t[i];
    sort(t,t+n);
    for(int i=0;i<n;++i)
        if(t[i].substr(0,l)==s){
            cout<<t[i];
            return;
        }
    cout<<s;
}