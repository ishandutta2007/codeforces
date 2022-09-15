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
    int n;
    cin>>n;
    int best=-3000;
    string name;
    for(int i=0;i<n;++i){
        string nam;
        int pl,m,a,b,c,d,e;
        cin>>nam>>pl>>m>>a>>b>>c>>d>>e;
        if(best<100*pl-50*m+a+b+c+d+e){
            best=100*pl-50*m+a+b+c+d+e;
            name=nam;
        }
    }
    cout<<name;
}