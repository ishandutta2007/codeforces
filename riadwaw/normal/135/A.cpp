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
#include <cstdlib>
using namespace std;
void solve();

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
int a[101010];
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
     if(n==1 && a[0]==1){
         cout<<2;
         return;
     }
    sort(a,a+n);
    cout<<1<<' ';
    for(int i=0;i<n-1;++i){
        if(i==n-2 && a[n-1]==1)
            cout<<2<<' ';
        else
            cout<<a[i]<<' ';
    }
}