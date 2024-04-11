#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
#define mp make_pair
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
int ar[111];
void solve(){
    memset(ar,0,sizeof(ar));
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        int a;
        scanf("%d",&a);
        ++ar[a];
    }
    int c=0;
    while(ar[k]!=n){
        ++c;
        for(int i=k;i>1;--i){
            if(ar[i-1]>0){
                --ar[i-1];
                ++ar[i];
            }
        }
    }
    cout<<c;
}