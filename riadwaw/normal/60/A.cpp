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
typedef pair<int, int> pi;
typedef pair<li, li> pli;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
bool x[10000];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        x[i]=1;
    }
    for(int i=0;i<m;++i){
        string s,t;
        int a;
        cin>>t>>t>>s>>t>>a;
        if(s[0]=='r'){
            for(int j=1;j<=a;++j)
                x[j]=0;
        }
        else{
            for(int j=a;j<=n;++j)
                x[j]=0;
        }
    }
    int c=0;
    for(int i=1;i<=n;++i)
        if(x[i])
            ++c;
    if(c)
        cout<<c;
    else
        cout<<-1;
}