#include <bits/stdc++.h>

const int max_N=1e5,Types=1<<5;

int n,k,state[max_N+21],cnt[Types];

bool ans;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        state[i]=0;
        for(int j=0,x;j<k;++j){
            scanf("%d",&x);
            state[i]|=x<<j;
        }
        if(!state[i])ans=1;
        ++cnt[state[i]];
    }
    for(int i=1;i<(1<<k);++i)if(cnt[i])
        for(int j=i+1;j<(1<<k);++j)if(cnt[j]){
            if(i&j)continue;
            ans=1;
        }
    puts(ans?"YES":"NO");
    return 0;
}