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
    int n,b[2001],d;
    cin>>n>>d;
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    li ans=0;
    for(int i=1;i<n;++i){
        if(b[i]>b[i-1])
            continue;
        ans+=(b[i-1]-b[i])/d+1;
        b[i]+=((b[i-1]-b[i])/d+1)*d;
    }
    cout<<ans;
}