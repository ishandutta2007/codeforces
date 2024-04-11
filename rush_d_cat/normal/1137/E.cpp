#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int n,m; LL cnt;
pair<LL,LL> stk[N]; double slope[N]; int top;
LL sumB,sumk[N];
int main() {
    scanf("%d%d",&n,&m);
    slope[0]=-1e18; stk[0]=make_pair(0,0);
    cnt=n-1;

    int cas=0;
    while(m--) {
        int op,k,b,s;
        scanf("%d",&op);
        if(op==1) {
            scanf("%d",&k);
            cnt+=k;sumB=0;top=0;sumk[0]=0;
        }
        if(op==2) {
            scanf("%d",&k);
            pair<LL,LL> now = make_pair(cnt+1, -sumB);
            //printf("in %lld %lld\n", now.first,now.second);
            while(true) {
                //printf("pre = (%lld,%lld)\n", stk[top].first,stk[top].second);
                double y = stk[top].second + sumk[top]*stk[top].first;
                double tmpslope = 1.0 * (now.second-y) / (now.first-stk[top].first);
                //double preslope = 1.0 * ((stk[top-1].second + (sumk[top-1]+sumk[top]) * stk[top-1].first) - (stk[top].second + sumk[top] * stk[top].first)) / (stk[top-1].first - stk[top].first);
                //printf("tmpslope = %.7f\n", tmpslope);
                if (tmpslope < slope[top]) {
                    sumk[top-1] += sumk[top];
                    -- top;
                } else {
                    slope[top+1] = tmpslope;
                    break;
                }
            }
            if(slope[top+1] < -1e-12)
                stk[++top]=now,sumk[top]=0; 
            cnt=cnt+k;
        }
        if(op==3) {
            scanf("%d%d",&b,&s);
            sumB+=b;
            sumk[top]+=s;
            while(top) {
                //printf("! %lld\n", stk[top-1].second + (sumk[top-1]+sumk[top]) * stk[top-1].first + sumB);
                slope[top] = 1.0 * ((stk[top-1].second + (sumk[top-1]+sumk[top]) * stk[top-1].first) - (stk[top].second + sumk[top] * stk[top].first)) / (stk[top-1].first - stk[top].first);
                if(stk[top-1].second + (sumk[top-1]+sumk[top]) * stk[top-1].first <= stk[top].second + sumk[top] * stk[top].first) {
                    sumk[top-1] += sumk[top];
                    -- top;
                } else {
                    break;
                }
            }
        }

        //++cas; if(cas==497/2 && stk[top].first==4) {
        //    printf("%d%d\n", top,op);return 0;
        //}
        //printf("# %lld + %lld * %lld + %lld\n", stk[top].second,sumk[top],stk[top].first,sumB);
        printf("%lld %lld\n", stk[top].first+1, stk[top].second + sumk[top]*stk[top].first + sumB);
    }
}