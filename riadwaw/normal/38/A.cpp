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
    int n,d[111];
    cin>>n;
    for(int i=1;i<n;++i){
        cin>>d[i];
    }
    int l,r;
    cin>>l>>r;
    int s=0;
    for(int i=l;i<r;++i){
        s+=d[i];
    }
    cout<<s;
}