#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int,int> pi;
void solve();
int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}
bool ar[1010][1010];
int str[1010],stolb[1010];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int j=0;j<m;++j)
        stolb[j]=-1;
    for(int i=0;i<n;++i){
        str[i]=-1;
        for(int j=0;j<m;++j){
            char c;
            cin>>c;
            if(ar[i][j]=(c=='*')){
                ++str[i];
                ++stolb[j];
            }
        }
    }
    for(int i=0;i<n;++i){
    }
    li r=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(ar[i][j]){
                r+=(li)str[i]*stolb[j];
            }
        }
    }
    cout<<r;
}