#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
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
    int n,k,a[10101],s=0;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
        s+=a[i];
    }
    ld l=0,r=s;
    for(int i=0;i<100;++i){
        ld c=(l+r)/2;
        ld bal=0;
        for(int i=0;i<n;++i){           
            if(a[i]>c){
                bal+=(a[i]-c)*(100-k)/100;
            }
            else{
                bal-=(c-a[i]);
            }
        }
        if(bal>0){
            l=c;
        }
        else
            r=c;
    }
    printf("%.10lf",(l+r)/2);
}