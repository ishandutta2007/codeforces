#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=5000+10;
int n,m,q,w[N];
int cnt[N],sum[N][102];
char s[N];

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=m;i++) {
        scanf("%s", s);
        int sum_=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') sum_+=(1<<i);
        }
        cnt[sum_] ++;
    }
    for(int i=0;i<1<<n;i++) {
        for(int mask=0;mask<1<<n;mask++) {
            int dis=0;
            for(int bit=0;bit<n;bit++) {
                if( ((i>>bit)&1) == ((mask>>bit)&1) )
                    dis += w[bit];
            }
            if (dis<=100) sum[i][dis] += cnt[mask];
        }
        for(int j=1;j<=100;j++) {
            sum[i][j] += sum[i][j-1];
        }
    }
    while(q--) {
        int k;
        scanf("%s%d", s,&k);
        int sum_=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') sum_+=(1<<i);
        }    
        printf("%d\n", sum[sum_][k]);
    }
}