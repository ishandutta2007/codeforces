#include <iostream>
#include <vector>
using namespace std;
const int N = 102;
int n,m[N],d[N],p[N],t[N];
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int sum[1002];
int id(int m,int d) {
    int ans=0;
    for(int i=0;i<m-1;i++) ans+=day[i];
    ans+=d;
    return ans+500;
}

int main() {
    //printf("%d\n", id(12,31));
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&m[i],&d[i],&p[i],&t[i]);
        sum[id(m[i],d[i])] -= p[i];
        sum[id(m[i],d[i]) - t[i]] += p[i];
    }
    int ans=0;
    for(int i=1;i<=1000;i++) {
        sum[i]+=sum[i-1]; ans=max(ans, sum[i]);
    }
    printf("%d\n", ans);
}