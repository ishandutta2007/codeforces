#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
li m[1000];
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        m[a+10]++;
    }
    long long ans=(m[10]*(m[10]-1)/2);
    
    for(int i=1;i<=10;++i){
        //cout<<m[i+10]<<' ';
        ans+=(m[i+10])*(m[10-i]);
    }
    cout<<ans;
}