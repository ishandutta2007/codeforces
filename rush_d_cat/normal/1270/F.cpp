#include <iostream>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=200000+10;
const int B=448;
char s[N];
int n,pre[N],l[N],r[N]; LL c[N];
unordered_map<int,int> mp;
int v[N],tot;
int main(){
    //for(int i=1;i<=200000;i++)s[i]=rand()%2?'0':'1';
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(s[i]=='1'?1:0);
    }
    LL ans=0;
    
    for(int k=1;k<=B;k++){
        for(int i=0;i<=n;i++)v[i]=pre[i]*k-i;
        sort(v,v+1+n);
        for(int i=0,j=0;i<=n;i=j){
            while(j<=n&&v[j]==v[i])++j;
            ans=ans+1LL*(j-i)*(j-i-1)/2;
        }
    }

    for(int i=0,j=0;i<=n;i=j){
        while(j<=n && pre[j]==pre[i])++j;
        l[pre[i]]=i,r[pre[i]]=j-1;
    }
    for(int i=0;i<=pre[n];i++){
        for(int j=l[i];j<=r[i];j++){
            for(int k=i+1;k<=min(pre[n],i+B);k++){
                //printf("j=%d, [%d,%d]\n", j,l[k],r[k]);
                int lef=l[k],rig=r[k];
                int pl=(lef-j+(k-i-1))/(k-i), pr=(rig-j)/(k-i);
                //printf("add [%d,%d]\n", pl,pr);
                if(pl<=pr)c[pl]++,c[pr+1]--;
            }
        }
    }
    for(int i=1;i<N;i++)c[i]+=c[i-1];

    for(int i=B+1;i<N;i++)ans+=c[i];
    cout<<ans<<endl;
}
/*
pre[i] * k - i
*/