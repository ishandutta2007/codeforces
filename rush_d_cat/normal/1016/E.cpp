#include <iostream>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n;
LL l[N],r[N];
LL sum[N];
double sy,a,b;
int main() {
    scanf("%lf%lf%lf",&sy,&a,&b);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld%lld",&l[i],&r[i]);
        sum[i]=sum[i-1]+r[i]-l[i];
    }
    l[0]=-1e12-1, r[0] = -1e12; 
    l[n+1]=1e12, r[n+1]=1e12+1;
    int q; scanf("%d",&q);
    while(q--) {
        double x,y;
        scanf("%lf%lf",&x,&y);
        double pl = a + (x-a) * (-sy) / (y-sy);
        double pr = b - (b-x) * (-sy) / (y-sy);
        //printf("pl = %.5f, pr = %.5f\n", pl, pr);  
        int L=0,R=n+1;
        while(R-L>1) {
            // >= pl
            int mid=(L+R)>>1;
            if(l[mid]>=pl) R=mid;
            else L=mid;
        }
        int segL = R;

        L=0,R=n+1;
        while(R-L>1) {
            int mid=(L+R)>>1;
            if(r[mid]<=pr) L=mid;
            else R=mid;
        } 
        int segR = L;
        //printf("[%d, %d]\n", segL, segR);
        if (segL > segR+1) {
            printf("%.9f\n", b-a); continue;
        }

        double ans = (sum[segR] - sum[segL-1]);
        if (segL !=0&&r[segL-1] > pl) ans += r[segL-1] - pl;
        if (segR !=n+1&&l[segR+1] < pr) ans += pr - l[segR+1];
        //printf("%.9f\n", ans);
        ans = ans * (y-sy) / y;
        printf("%.9f\n", ans);
    }
}