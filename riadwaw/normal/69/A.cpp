#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    int sx=0,sy=0,sz=0;
    for(int i=0;i<n;++i){
        int x,y,z;
        cin>>x>>y>>z;
        sx+=x;
        sy+=y;
        sz+=z;
    }
    if(sx || sy || sz)
        cout<<"NO";
    else
        cout<<"YES";
}