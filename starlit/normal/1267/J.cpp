#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2000200;
const int inf=1000000000;
int T,n,c[N],mn,ans;
vector<int>V;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);V.clear(),mn=inf,ans=0;
        for(int i=0,x;i<n;i++)scanf("%d",&x),c[x]++;
        for(int i=1;i<=n;i++)if(c[i])V.pb(c[i]),mn=min(mn,c[i]),ans+=c[i],c[i]=0;
        for(int s=2;s<=mn+1;s++){
            bool flag=true;int res=0;
            for(int j=0;j<V.size()&&flag;j++){
                int l=1,r=s-2-(V[j]/s),d=V[j]%s;
                if(l<=r&&d<=r&&d>=l)flag=false;
                int x=V[j]/(s-1),y=V[j]%(s-1);
                x-=y,y+=x/s*(s-1),x%=s,res+=x+y;
            }
            if(flag)ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
}