#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const ld eps=1e-9;
const int N=(int)2e6+5,mod=1e9+7;
int n,sum[N];
char s[N];
vector<int>p;
int ans,ansu,ansv,mi,tl;
void sol1(){
    int su=-1,sv=-1;
    for(int i=p.front();i;--i)if(s[i]==')'){su=i;break;}
    for(int i=p.back()+1;i<=n;++i)if(s[i]=='('){sv=i;break;}
    if(su!=-1&&sv!=-1){
        int mit=0;
        for(int i=su;i<sv;++i)sum[i]+=2;
        int num=0;
        rep(i,n)mit=min(mit,sum[i]);
        rep(i,n)if(mit==sum[i])++num;
        //printf("%d %d\n",su,sv);
        if(num>ans){
            ans=num;
            ansu=su;ansv=sv;
        }
        for(int i=su;i<sv;++i)sum[i]-=2;
    }
}
void sol3(){
    int ku=-1,kv=-1;
    rep(i,n)if(sum[i]==mi+1||sum[i]==mi){ku=i;break;}
    for(int i=n;i;--i)if(sum[i]==mi+1||sum[i]==mi){kv=i;break;}
    if(ku==-1||kv==-1)return;
    int su=-1,sv=-1;
    for(int i=ku;i;--i)if(s[i]==')'){su=i;break;}
    for(int i=kv+1;i<=n;++i)if(s[i]=='('){sv=i;break;}
    if(su!=-1&&sv!=-1){
        int mit=0;
        for(int i=su;i<sv;++i)sum[i]+=2;
        int num=0;
        rep(i,n)mit=min(mit,sum[i]);
        rep(i,n)if(mit==sum[i])++num;
        //printf("%d %d\n",su,sv);
        if(num>ans){
            ans=num;
            ansu=su;ansv=sv;
        }
        for(int i=su;i<sv;++i)sum[i]-=2;
    }
}
void sol(int x,int y){
    int su=-1,sv=-1;
    for(int i=x+1;i<=y;++i)if(s[i]=='('){su=i;break;}
    for(int i=y;i>=x+1;--i)if(s[i]==')'){sv=i;break;}
    if(su!=-1&&sv!=-1&&su<sv){
        int num=tl;
        for(int i=su;i<sv;++i)if(sum[i]==mi+2)++num;
        //printf("%d %d\n",su,sv);
        if(num>ans){
            ans=num;
            ansu=su;ansv=sv;
        }
    }
}

void sol_d(int x,int y){
    int su=-1,sv=-1;
    for(int i=x+1;i<=y;++i)if(s[i]=='('){su=i;break;}
    for(int i=y;i>=x+1;--i)if(s[i]==')'){sv=i;break;}
    if(su!=-1&&sv!=-1&&su<sv){
        int num=0;
        for(int i=su;i<sv;++i)if(sum[i]==mi+1)++num;
        //printf("%d %d\n",su,sv);
        if(num>ans){
            ans=num;
            ansu=su;ansv=sv;
        }
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    sum[0]=0;rep(i,n)sum[i]=sum[i-1]+(s[i]=='('?1:-1);
    if(sum[n]!=0){
        printf("0\n1 1\n");
        return 0;
    }
    mi=0;
    rep(i,n)if(mi>sum[i])mi=sum[i];
    //rep(i,n)printf("%d ",sum[i]);puts("");
    rep(i,n)if(mi==sum[i])p.pb(i);
    ans=tl=p.size(),ansu=ansv=1;
    sol1();
    sol3();
    p.clear();
    rep(i,n)if(mi==sum[i]||mi+1==sum[i])p.pb(i);


    sol(0,p.front());
    for(int i=0;i<(int)p.size()-1;++i){
        sol(p[i],p[i+1]);
    }
    sol(p.back(),n);//??

    p.clear();

    rep(i,n)if(mi==sum[i])p.pb(i);


    sol_d(0,p.front());
    for(int i=0;i<(int)p.size()-1;++i){
        sol_d(p[i],p[i+1]);
    }
    sol_d(p.back(),n);//??

    printf("%d\n%d %d\n",ans,ansu,ansv);
    return 0;
}