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
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

int win[101010];

bool cmp(int a, int b){
    return win[a] > win[b];
}
void solve(){
    int n,k;
    cin>>n>>k;
    li mer;
    cin>>mer;
    int ar[101010];
    for(int i=0;i<n;++i){
        cin>>win[i];
        ar[i] = i;
    }
    sort(ar, ar+n-1, cmp);
    int where[101010];
    k = min(k, n-1);
    if(k==n-1){
        long long sum = 0;
        for(int i=0;i<n - 1;++i){
            sum += win[i];
        }
        if(sum > mer){
            cout<<1;
        }
        else
            cout<<n;
        return;
    }
    for(int i=0;i<n-1;++i){
        where[ar[i]] = i;
    }
    
//  for(int i=0;i<n-1;++i){
//      cerr<<ar[i] << ' ';
//  }
    
    li sumpref = 0;
    for(int i=0;i < k - 1;++i){
        sumpref += win[ar[i]];
        
    }
    li sumadd = sumpref + win[ar[k-1]];
    //cerr<<sumadd<<endl;
    for(int i=0;i<n -1;++i){
        li need;
        if(where[i] >= k){
            need = sumpref + win[i];
        }
        else{
            need = sumadd;
        }
        cerr<<i<<' '<<need<<endl;
        if(need > mer){
            cout<<(i + 1);
            return;
        }
    }
    cout<<n;
}