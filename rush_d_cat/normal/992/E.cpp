#include <iostream>
using namespace std;
const int N=2000000+10;
typedef long long LL;
int n,q;
LL a[N],bit[N];
void add(int x,int val) {
    while(x<N) bit[x]+=val, x+=x&(-x);
}
LL sum(int x) {
    LL ans=0;
    while(x) ans+=bit[x], x-=x&(-x);
    return ans;
}
int query(LL x) {
    int now=0; LL s=0;
    for(int i=18;i>=0;i--){
        if((now|1<<i) <= n && s+bit[now|(1<<i)]<x)
            now|=1<<i, s+=bit[now];
    }
    return now;
}
int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        add(i,a[i]);
    }
    while(q--){
        int p,x; scanf("%d%d",&p,&x);
        add(p,x-a[p]), a[p]=x;
        LL cur_sum=0, cur_pos=0;

        bool find_ans=0;
        while(true) {

            //printf("cur_pos = %d, cur_sum = %d\n", cur_pos, cur_sum);
            if(sum(cur_pos)==a[cur_pos+1]) {
                printf("%lld\n", cur_pos+1);
                find_ans=1; 
                break;
            } else {
                cur_sum=cur_sum*2;
                cur_pos=query(cur_sum);
                //printf("%d %d\n", cur_pos, sum(cur_pos));
                if(sum(cur_pos)==a[cur_pos+1]) {
                    printf("%lld\n", cur_pos+1);
                    find_ans=1; break;
                }
                cur_pos ++, cur_sum = sum(cur_pos);
            }
            if (cur_pos == n+1) break;
            //printf("cur_pos = %d, cur_sum = %d\n", cur_pos, cur_sum);
        }
        if(!find_ans) printf("-1\n");
    }
}