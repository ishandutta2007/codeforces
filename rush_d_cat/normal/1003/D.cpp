#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N=200000+10;
set<int> st;
int n,q;
int a[N],d[N];
int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int x=a[i],cnt=0;
        while(x!=1) x/=2, cnt++;
        d[cnt]++;
    }
    //printf("%d\n", d[1]);
    while(q--){
        int x;scanf("%d",&x);
        int t=x,ans=0;
        for(int i=31;i>=0;i--){
            ans+=min(t/(1<<i), d[i]);
            t=t-(1<<i)*min((t/(1<<i)),d[i]);
            //printf("i = %d, cur = %d\n", i, t);
        }
        if(t==0) {
            printf("%d\n", ans);
        } else {
            printf("-1\n");
        }
        t=x;
    }
}