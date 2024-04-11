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
void solve(){
    int n,x[101010];
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d",x+i);
    }
    li ans=0;
    int f=0;
    for(int i=0;i<n;++i){
        if(x[i]==x[f])
            continue;
       li c=i-f;
        ans+=c*(c-1)/2+c;
        f=i;
        //cout<<i<<' '<<c*c<<endl;
    }
    li c=n-f;
    ans+=c*(c-1)/2+c;
    cout<<ans;
}