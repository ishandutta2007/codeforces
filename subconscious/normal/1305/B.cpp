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
const int N=3e6+5,mod=1e9+7;
char s[N],t[N];
int n,k;
bool is[N];
vector<int>ans[N];
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    k=0;
    do{
        ++k;
        int l=1,r=n;
        //printf("%s\n",s+1);
        while(l<=r){
            while(l<=r&&s[l]!='(')++l;
            while(l<=r&&s[r]!=')')--r;
            //printf("%d %d\n",l,r);getchar();
            if(l<=r&&s[l]=='('&&s[r]==')')ans[k].pb(l),ans[k].pb(r),++l,--r;
        }
        sort(ans[k].begin(),ans[k].end());
        rep(i,n)is[i]=0;
        for(int v:ans[k])is[v]=1;
        int top=0;
        rep(i,n)if(!is[i])t[++top]=s[i];
        n=top;
        rep(i,n)s[i]=t[i];
        s[n+1]='\0';
    }while(ans[k].size()>0);
    --k;
    printf("%d\n",k);
    rep(i,k){
        printf("%d\n",(int)ans[i].size());
        for(int j=0,mx=ans[i].size();j<mx;++j)
            printf("%d%c",ans[i][j]," \n"[j+1==mx]);
    }
}