#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500000+10;

int n,k,d;
int bit[N],a[N];
void update(int p) {
    while(p<N) {
        bit[p]++;
        p+=p&-p;
    }
}
int sum(int x) {
    x=max(x,0);
    int ans=0;
    while(x){
        ans+=bit[x];
        x-=x&-x;
    }
    return ans;
}

int main() {
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);

    sort(a+1,a+1+n);
    
    update(1);

    for(int i=1;i<=n;i++) {
        int l = lower_bound(a+1,a+1+n,a[i]-d)-a-1;
        int r = i-k;
        if( sum(r+1)-sum(l) > 0) {
            update(i+1);
            if(i==n) {
                return !printf("YES\n");
            }
        }
    }
    printf("NO\n");

}