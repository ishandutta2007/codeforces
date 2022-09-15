#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long li;
typedef pair<li, li> pli;
typedef long double ld;
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
    cout<<n;
    if(n==1)
        return;
    for(int i=2;i*i<=n;++i)
        if(n%i==0){
            n/=i;
            cout<<' '<<n;
            i--;
        }
    cout<<' '<<1;
}