#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=998244353;
int a,b,T;
bool is[N];
vector<int>ans;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&a,&b);
        int u=(a+b+1)/2,v=a+b-u;
        for(int i=0;i<=a+b;++i)is[i]=0;
        for(int i=0;i<=u&&i<=a;++i){
            int j=u-i,k=a-i,p=b-j;
            if(j<0||k<0||p<0)continue;
            is[i+p]=1;
        }
        swap(u,v);
        for(int i=0;i<=u&&i<=a;++i){
            int j=u-i,k=a-i,p=b-j;
            if(j<0||k<0||p<0)continue;
            is[i+p]=1;
        }

        ans.clear();
        for(int i=0;i<=a+b;++i)if(is[i])ans.pb(i);
        printf("%d\n",(int)ans.size());
        for(int i=0,mx=ans.size();i<mx;++i)printf("%d%c",ans[i]," \n"[i+1==mx]);
    }
    return 0;
}
/*
    a b
u   i j
v   k p
*/