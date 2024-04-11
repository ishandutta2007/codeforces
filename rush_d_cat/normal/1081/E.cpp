#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200000+10;
int n; LL x[N],y[N],mn[N],sum[N];
vector<int> d[N];
int main() {
    for(int i=1;i<N;i++){
        mn[i]=1e16;
        for(int j=2*i;j<N;j+=i) d[j].push_back(i);
    }
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++){
        scanf("%lld",&x[i]);
        for(auto p: d[x[i]]) {
            if(p >= x[i]/p) continue;
            if((x[i]/p - p)%2) continue;
            int s = (x[i]/p - p) / 2;
            int t = (x[i]/p + p) / 2;
            //printf("s=%d, t=%d, p=%d\n", s,t,p);
            if(mn[i-1] < s) {
                if (t < mn[i])
                mn[i] = t; 
            }
        }
    }

    if(mn[n/2]>1e15) return !printf("No\n");

    for(int i=1;i<=n/2;i++){
        sum[2*i-1] = (LL)mn[i]*mn[i] - x[i];
    }
    for(int i=1;i<=n;i++){
        if(i%2==1) {
            y[i]=sum[i]-sum[i-1];
        } else {
            y[i]=x[i/2]; sum[i]=sum[i-1]+y[i];
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++)
        printf("%lld ", y[i]);
}