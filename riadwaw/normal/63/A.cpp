#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
#define mp make_pair
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
string a[111],b[111];
int n;
void d(char c){
    for(int i=0;i<n;++i){
        if(b[i][0]==c)
            cout<<a[i]<<endl;
    }
}
void solve(){
    
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
        if(b[i][1]=='h')
            b[i][0]='w';
    }
    d('r');
    d('w');
    d('m');
    d('c');

}