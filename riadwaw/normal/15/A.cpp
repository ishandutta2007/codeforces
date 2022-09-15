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
    int n,t;
    cin>>n>>t;
    pi x[10000];
    for(int i=0;i<n;++i){
        cin>>x[i].first>>x[i].second;
        x[i].first*=2;
    }
    sort(x,x+n);
    set<int> ans;
    for(int i=0;i<n;++i){
        if((!i) || x[i].first-x[i].second-t-t>=x[i-1].first+x[i-1].second){
            ans.insert(x[i].first-x[i].second-t);
            cerr<<x[i].first-x[i].second-t<<endl;
        }
        if((i==n-1) || x[i].first+x[i].second+t+t<=x[i+1].first-x[i+1].second){
            ans.insert(x[i].first+x[i].second+t);
            cerr<<x[i].first+x[i].second+t<<endl;
        }
    }
    cout<<ans.size();
}