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

using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
int a[20202];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int> d;
    d.push_back(n);
    if(n%2==0 && n!=4)
        d.push_back(n/2);
    for(int i=3;i*i<=n;++i){
        if(n%i == 0){
            d.push_back(i);
            d.push_back(n/i);
        }
    }
    int ans = -100000000;
    for(int i=0;i<int(d.size());++i){
        //cout<<"d[i]="<<d[i]<<endl;
        for(int j=0;j<n/d[i];++j){
            int s = 0;
            for(int k=j;k<n;k+=n/d[i]){
        //      cout<<k<<' ';
                s+=a[k];
            }
        //  cout<<endl;
            ans = max(ans,s);
        }
    }
    cout<<ans;
}