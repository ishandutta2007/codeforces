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
int b[1111111];
int a[1111111];
int e[1111111];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int m;
        scanf("%d",&m);
        b[m]=i;
    }
    for(int i=0;i<n;++i){
        int m;
        scanf("%d",&m);
        a[i]=b[m];
    }
    reverse(a,a+n);
    e[0]=0;
    int max=0;
    for(int i=0;i<n;++i){
        int l=0;
        int r=max+1;
        while(l+1<r){
            int c=(l+r)/2;
            if(e[c]>a[i])
                r=c;
            else
                l=c;
        }
        e[r]=a[i];
        if(r==max+1)
            ++max;
    }
    cout<<max;
    
}