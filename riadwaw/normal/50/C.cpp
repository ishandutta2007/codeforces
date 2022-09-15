#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
typedef long long int li;
int zmin(int a,int b){
    return min(abs(a),abs(b));
}
int main ()
{
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    int INF=-10000000;
    int l=-INF,r=INF,u=INF,d=-INF;
    int a[100011][2];
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i][0]>>a[i][1];
        if(a[i][0]>r)
            r=a[i][0];
        if(a[i][0]<l)
            l=a[i][0];
        if(a[i][1]>u)
            u=a[i][1];
        if(a[i][1]<d)
            d=a[i][1];
    }
    int ld=-INF,lu=-INF,ru=-INF,rd=-INF;
    for(int i=0;i<n;++i){
        if(a[i][0]-l+a[i][1]-d<ld)
            ld=a[i][0]-l+a[i][1]-d;
        if(a[i][0]-l-a[i][1]+u<lu)
            lu=a[i][0]-l-a[i][1]+u;
        if(r-a[i][0]-a[i][1]+u<ru)
            ru=r-a[i][0]-a[i][1]+u;
        if(r-a[i][0]+a[i][1]-d<rd)
            rd=r-a[i][0]+a[i][1]-d;
    }
    cout<<(u-d+r-l+4)*2-ld-lu-ru-rd-4;
    return 0;
}