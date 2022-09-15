#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <queue>
#include <stack>
using namespace std;
int cnt[256];
typedef long long li;
typedef pair<int,int> pi;
void solve();
int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    
    while(t--)
        solve();    
    return 0;
}

int a[101010];
int b[101010];
void solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n ;++i){
        cin>>a[i];
        b[i] = a[i];

    }
    sort(a, a+n);
    int c = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] != b[i])
            ++c;
    }

    if(c <= 2){
        cout<<"YES";
    }
    else
        cout<<"NO";
}