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
    int n;
    cin>>n;
    for(int i=1;i<(n+2)/2;++i)
        cout<<i<<' '<<n+1-i<<' ';
    if(n%2)
        cout<<(n+1)/2;
}