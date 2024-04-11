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
    int n,p1,p2,p3,t1,t2;
    pi x[111];
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    int ans=0;
    for(int i=0;i<n;++i){
        cin>>x[i].first>>x[i].second;
        ans+=(x[i].second-x[i].first)*p1;
    }
    for(int i=1;i<n;++i){
        if(x[i].first-x[i-1].second>t1){
            ans+=p1*t1;
            if(x[i].first-x[i-1].second-t1>t2){
                ans+=p2*t2;
                ans+=(x[i].first-x[i-1].second-t1-t2)*p3;
            }
            else
                ans+=(x[i].first-x[i-1].second-t1)*p2;
        }
        else{
            ans+=(x[i].first-x[i-1].second)*p1;
        }
    }
    cout<<ans;
}