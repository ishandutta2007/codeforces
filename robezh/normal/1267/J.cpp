#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;

int n;
int sum[maxn*2];

void solve(int tnum) {
    scanf("%d",&n);
    map<int,int> cnt;
    for(int i=1;i<=n;i++) {
        int x; scanf("%d",&x);
        cnt[x]++;
    }

    int ok = 0;
    for(int i=1;i<=n;i++) sum[i] = 0;
    for(auto tmp : cnt) {
        sum[tmp.second]++;
        ok++;
    }
    for(int i=1;i<=n;i++) sum[i] += sum[i-1];

    for(int s=n;s>=1;s--) {
        int wow = 0;
        for(int i=0;i<=n/s;i++) {
            //printf("\t[%d, %d]\n",s*i,s*i-1+min(s,i+1));
            wow += sum[min(n,s*i-1+min(s,i+1))] - sum[s*i-1];
        }
        //printf("wow = %d : %d\n",s,wow);
        if(wow == ok) {
            s++;
            int ans = 0;
            for(auto tmp : cnt) {
                ans += (tmp.second+s-1)/s;
            }
            printf("%d\n",ans);
            return ;
        }
    }
    printf("%d\n",n);
}

int main() {
    int tnum; scanf("%d",&tnum);
    for(int i=1;i<=tnum;i++) solve(i);
}