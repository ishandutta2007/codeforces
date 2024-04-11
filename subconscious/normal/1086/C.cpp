#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck
#define y0 fuxk
#define x1 fxck
#define y1 fxxk
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-9;
int T,k,n;
char s[N],a[N],b[N];
char w[500];bool is[500];
vector<int>fk;
bool trymax(int i){
    fk.clear();
    for(;i<=n;++i){
        if(w[s[i]]){
            if(w[s[i]]<a[i])return 0;
            if(w[s[i]]>a[i])return 1;
            continue;
        }
        for(char j='a'+k-1;j>='a';--j)if(!is[j]&&j>=a[i]){
            w[s[i]]=j;is[j]=1;fk.pb(s[i]);break;
        }
        if(w[s[i]]==0)return 0;
        if(w[s[i]]>a[i])return 1;
    }
    return 1;
}
bool trymin(int i){
    fk.clear();
    for(;i<=n;++i){
        if(w[s[i]]){
            if(b[i]<w[s[i]])return 0;
            if(w[s[i]]<b[i])return 1;
            continue;
        }
        for(char j='a';j<='a'+k-1;++j)if(!is[j]&&j<=b[i]){
            w[s[i]]=j;is[j]=1;fk.pb(s[i]);break;
        }
        if(w[s[i]]==0)return 0;
        if(w[s[i]]<b[i])return 1;
    }
    return 1;
}
bool sol(){
    for(char i='a';i<='a'+k-1;++i)w[i]=0,is[i]=0;
    /*rep(i,n){
        if(w[s[i]]){
            if(w[s[i]]<a[i])return 0;
            if(b[i]<w[s[i]])return 0;
            continue;
        }
        if(a[i]>b[i])return 0;
        if(a[i]+1<=b[i]-1){
            for(char j=a[i]+1;j<=b[i]-1;++j)if(!is[j]){
                w[s[i]]=j;is[j]=1;return 1;
            }
        }
        if(!is[a[i]]){
            w[s[i]]=a[i];is[a[i]]=1;

        }
        if(!is[b[i]]){

        }
    }*/
    int i=1;
    for(;i<=n;++i){
        if(a[i]!=b[i])break;
        if(w[s[i]]==0){

            if(is[a[i]])return 0;
            w[s[i]]=a[i];is[a[i]]=1;
        }else if(w[s[i]]!=a[i])return 0;
    }
    if(i<=n){
        if(a[i]>b[i])return 0;
        if(a[i]+1<=b[i]-1){
            for(char j=a[i]+1;j<=b[i]-1;++j)if((w[s[i]]==0&&!is[j])||w[s[i]]==j){
                w[s[i]]=j;is[j]=1;return 1;
            }
        }
        bool flag0=0,flag1=0;
        if(w[s[i]]==a[i])flag0=1;
        if(w[s[i]]==b[i])flag1=1;
        if(flag0||(w[s[i]]==0&&!is[a[i]])){
            w[s[i]]=a[i];is[a[i]]=1;//printf("%c %c\n",s[i],a[i]);
            if(trymax(i+1))return 1;
            else {for(auto p:fk)is[w[p]]=0,w[p]=0;if(!flag0){is[a[i]]=0,w[s[i]]=0;}}
        }
        if(flag1||(w[s[i]]==0&&!is[b[i]])){
            w[s[i]]=b[i];is[b[i]]=1;//printf("%c %c\n",s[i],b[i]);
            if(trymin(i+1))return 1;
            else {for(auto p:fk)is[w[p]]=0,w[p]=0;if(!flag1){is[b[i]]=0,w[s[i]]=0;}}
        }
        return 0;
    }
    return 1;
}
void fix(){
    //for(char j='a';j<='a'+k-1;++j)printf("%c %d\n",w[j],is[j]);
    for(char i='a';i<='a'+k-1;++i)
        if(!w[i]){
         for(char j='a';j<='a'+k-1;++j)
            if(!is[j]){w[i]=j;is[j]=1;break;}
        }
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&k);
        scanf("%s",s+1);
        scanf("%s",a+1);
        scanf("%s",b+1);
        n=strlen(s+1);
        if(sol()){
            fix();
            puts("YES");
            for(char i='a';i<='a'+k-1;++i)putchar(w[i]);
            putchar('\n');
        }else puts("NO");
    }
    return 0;
}