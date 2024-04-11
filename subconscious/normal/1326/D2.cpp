#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuck1
#define y0 fuck2
#define x1 fuck3
#define y1 fuck4
#define mp make_pair
#define pb push_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=998244353;
int T,n,cnt;

char st[N*2], s[N];
int len, p[N*2]; //p[i]i
void init(char *s){
    len=strlen(s);
    st[0]='$',st[1]='#'; //'$'
    for(int i=1;i<=len;i++)st[i*2]=s[i-1],st[i*2+1]='#';
    len=len*2+2;
    int mx=0,id=0;
    for(int i=1;i<=len;i++) {
        p[i]=(mx>i)?min(p[id*2-i]+1,mx-i):1;
        for(;st[i+p[i]]==st[i-p[i]];++p[i]);
        if (p[i]+i>mx)mx=p[i]+i,id=i;
        p[i]--;
    }
}

char ss[N];
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%s",s);
        n=strlen(s);
        init(s);
        cnt=0;
        rep(i,n)if(s[i-1]==s[n-i])++cnt;else break;
        if(cnt==n){
            puts(s);continue;
        }
        int ans=0;
        rep(i,2*n)if(i%2==1){
            if(i/2+p[i]/2+cnt>=n||i/2-p[i]/2+1-cnt<=1)
                ans=max(ans,min(i/2*2,(n-i/2)*2));
        }else if(i%2==0){
            if(i/2+p[i]/2+cnt>=n||i/2-p[i]/2-cnt<=1)
                ans=max(ans,min(i/2*2-1,(n-i/2)*2+1));
        }
        int top=0;
        rep(i,2*n)if(i%2==1){
            if(i/2+p[i]/2+cnt>=n||i/2-p[i]/2+1-cnt<=1){
                if(ans==min(i/2*2,(n-i/2)*2)){
                    rep(j,cnt)ss[top++]=s[j-1];
                    if(ans==i/2*2)for(int j=cnt+1;j<=i/2;++j)ss[top++]=s[j-1];
                    else for(int j=i/2-ans/2+cnt+1;j<=i/2;++j)ss[top++]=s[j-1];
                    rep(j,ans/2)ss[top++]=ss[ans/2-j];
                    break;
                }
            }
        }else if(i%2==0){
            if(i/2+p[i]/2+cnt>=n||i/2-p[i]/2-cnt<=1){
                if(ans==min(i/2*2-1,(n-i/2)*2+1)){
                    rep(j,cnt)ss[top++]=s[j-1];
                    if(ans==i/2*2-1)for(int j=cnt+1;j<=i/2;++j)ss[top++]=s[j-1];
                    else for(int j=i/2-ans/2+cnt;j<=i/2;++j)ss[top++]=s[j-1];
                    rep(j,ans/2)ss[top++]=ss[ans/2-j];
                    break;
                }
            }
        }
        ss[top++]='\0';
        printf("%s\n",ss);
    }
    return 0;
}