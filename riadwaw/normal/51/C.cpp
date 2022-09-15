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
    int cnt=500;
    int n,a[201010];
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    a[n]=1000000001;
    sort(a,a+n);
    ld l=0,r=2000000000;
    while(cnt--){
        ld c=(l+r)/2;
        int* k = upper_bound(a,a+n,a[0]+c+c);
        int* q = lower_bound(a,a+n,a[n-1]-c-c)-1;
        if(k==a+n || q<a || *k+2*c>=*q)
            r=c;
        else
            l=c;
    }
    printf("%.10lf\n%.10lf %.10lf %.10lf",l,a[0]+l,*upper_bound(a,a+n,a[0]+l+l+1e-10)+l,a[n-1]-l);
}