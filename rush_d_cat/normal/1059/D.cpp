#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 100000 + 10;
typedef long double LD;
const double INF = 1e18;
int n,x[N],y[N];
LD Abs(LD x) {
    return x<0?-x:x;
}
bool chk(LD r) {
    LD L = -1e18, R = 1e18;
    for(int i=1;i<=n;i++) {
        LD d = Abs(y[i]-r);
        if(d > r) return 0;
        d = sqrt(2*r*y[i] - (LD)y[i]*y[i]);
        LD lb = x[i] - d;
        LD rb = x[i] + d;
        L = max(L, lb);
        R = min(R, rb);
        if(L > R) {
            return 0;
        }
    }
    return 1;
}
int main() {
    scanf("%d",&n);
    int A=0,B=0,C=0;
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&x[i],&y[i]); 
        if(y[i]<0) A++;
        if(y[i]==0)B++;
        if(y[i]>0) C++;
        if(y[i]<0) y[i]=-y[i];
    }
    if(B>=2) return !printf("-1\n");
    if(A>=1&&C>=1) return !printf("-1\n");
    LD l = 0, r = 1e14;
    //cout<<chk(0.624)<<endl; return 0;
    for(int i=0;i<200;i++) {
        LD mid = (l+r)/2;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    printf("%.8Lf\n", r);
}