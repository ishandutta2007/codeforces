#include <stdio.h>
int cnt[10];
#define min(a,b) ((a)<(b)?(a):(b))
int main(){
    //freopen("in4.txt","r",stdin);
    int i,n,a;
    scanf("%d",&n);
    int sum=0;
    for(i=0;i<n;i++){
        scanf("%d",&a);
        sum+=a;
        cnt[a]++;
    }
    if(sum==1 || sum==2 || sum==5){
        puts("-1");
        return 0;
    }
    int mn=min(cnt[1],cnt[2]);
    int ans=mn;
    cnt[1]-=mn;
    cnt[2]-=mn;
    while(cnt[1]>=3){
        cnt[1]-=3;
        cnt[3]+=1;
        ans+=2;
    }
    while(cnt[2]>=3){
        cnt[2]-=3;
        cnt[3]+=2;
        ans+=2;
    }
    if(cnt[1]==1){
        if(cnt[3]) ans++;
        else ans+=2;
    }
    else if(cnt[1]==2) ans+=2;
    else if(cnt[2]==1){
        if(cnt[4]) ans++;
        else ans+=2;
    }
    else if(cnt[2]==2){
        ans+=2;
    }
    printf("%d\n",ans);

}