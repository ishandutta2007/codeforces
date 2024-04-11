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
#include <complex>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
typedef double ld;
void solve();

#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
#define int li

void solve(){
    int n,sum,mn[33],mx[33],summn=0,summx=0;
    cin>>n>>sum;
    for(int i=0;i<n;++i){
        cin>>mn[i]>>mx[i];
        summn+=mn[i];
        summx+=mx[i];
    }
    if(summn>sum || summx<sum){
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    for(int i=0;summn<sum;++i){
        int r=min(mx[i]-mn[i],sum-summn);
        mn[i]+=r;
        summn+=r;
    }
    for(int i=0;i<n;++i){
        cout<<mn[i]<<' ';
    }
}