#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,mod=1e9+7;
const ld eps=1e-12;
int s[N],t[N],p[N],q[N],n;
bool cmp0(int x,int y){return s[x]<s[y];}
bool cmp1(int x,int y){return t[x]<t[y];}
struct opt{
    int i,j,d;
};
vector<opt>ans;
int sta[N],top;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",s+i);
    rep(i,n)scanf("%d",t+i);
    rep(i,n)p[i]=q[i]=i;
    sort(p+1,p+n+1,cmp0);
    sort(q+1,q+n+1,cmp1);
    top=0;
    rep(i,n){
        int dis=s[p[i]]-t[q[i]];
        if(dis==0)continue;
        if(dis<0)sta[++top]=i;
        else{
            while(top>0&&s[p[i]]>t[q[i]]){
                int x=sta[top];
                int dif=min(s[p[i]]-t[q[i]],t[q[x]]-s[p[x]]);
                s[p[x]]+=dif,s[p[i]]-=dif,ans.pb({p[x],p[i],dif});
                if(t[q[x]]==s[p[x]])--top;
            }
            if(s[p[i]]>t[q[i]]){puts("NO");return 0;}
        }
    }
    if(top!=0){puts("NO");return 0;}
    puts("YES");
    printf("%d\n",(int)ans.size());
    for(opt p:ans)printf("%d %d %d\n",p.i,p.j,p.d);
}