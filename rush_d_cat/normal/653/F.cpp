#include <iostream>
#include <vector>
using namespace std;
const int N=500000+10;
typedef long long LL;
char s[N];int n;
int sa[N],height[N],rk[N],t1[N],t2[N],cc[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a], a2=a+k<n?y[a+k]:-1;
    int b1=y[b], b2=b+k<n?y[b+k]:-1;
    return a1==b1 && a2==b2;
}

void buildSa(int m){
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++)cc[i]=0;
    for(int i=0;i<n;i++)cc[x[i]=s[i]]++;
    for(int i=1;i<m;i++)cc[i]+=cc[i-1];
    for(int i=n-1;i>=0;i--)sa[--cc[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)
            if(sa[i]>=k)y[p++]=sa[i]-k;

        for(int i=0;i<m;i++)cc[i]=0;
        for(int i=0;i<n;i++)cc[x[y[i]]]++;
        for(int i=1;i<m;i++)cc[i]+=cc[i-1];
        for(int i=n-1;i>=0;i--)sa[--cc[x[y[i]]]]=y[i];
        swap(x,y); m=1; x[sa[0]]=0;
        for(int i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i],sa[i-1],k)?m-1:m++;
        if(m>=n)break;
    }
}
void buildH(){
    for(int i=0;i<n;i++)rk[sa[i]]=i;
    height[0]=0; int k=0;
    for(int i=0;i<n;i++){
        if(!rk[i])continue;
        if(k)k--;
        int j=sa[rk[i]-1];
        //printf("i=%d, j=%d, k=%d\n", i,j,k);
        while(s[i+k]==s[j+k])k++;
        height[rk[i]]=k;
    }
}
vector<int> vec[N<<1]; int top,stk[N],nex[N],pre[N];
void buildSTK(){
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1] + (s[i-1]=='('?1:-1);    
        vec[pre[i]+N].push_back(i-1);
    }
    top=0;
    for(int i=n;i>=0;i--){
        while(top && pre[stk[top]] >= (i?pre[i]:0)) --top;
        nex[i]=top?stk[top]:n+1;
        //printf("nex[%d]=%d\n", i,nex[i]);
        stk[++top]=i;
        //printf("pre[%d]=%d\n", i,pre[i]);
    }
}

int main(){
    scanf("%d%s",&n,s);
    buildSa(1000); buildH(); buildSTK();

    LL ans=0;
    for(int i=0;i<n;i++){
        int pos=sa[i];
        int L=sa[i]+height[i];
        int R=nex[pos]-1;
        //printf("%s %d %d %d %d\n", s+sa[i],sa[i],L,R,height[i]);
        int cnt = lower_bound(vec[pre[pos]+N].begin(), vec[pre[pos]+N].end(), R) - lower_bound(vec[pre[pos]+N].begin(), vec[pre[pos]+N].end(), L);
        ans += max(cnt,0);
    }
    cout<<ans<<endl;
}