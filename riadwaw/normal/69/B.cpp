#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}

void solve(){
    int n,m,l[1111],r[1111],t[1111],c[1111];
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>l[i]>>r[i]>>t[i]>>c[i];
    }
    li sum=0;
    for(int i=1;i<=n;++i){
        int best=(1<<30),cbest=0;
        for(int j=0;j<m;++j){           
            if(l[j]<=i && r[j]>=i && best>t[j]){
                cbest=c[j];
                best=t[j];
            }           
        }
        sum+=cbest;
        //cout<<best<<' '<<cbest<<endl;
    }
    cout<<sum;
}