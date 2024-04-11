#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define eb emplace_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=1e9+7;
const ld eps=1e-12;
int n;char s[N],t[N];
bool check(){
    int now=0;
    rep(i,n){
        if(t[i]=='(')++now;
        else --now;
        if(now<0)return 0;
    }
    return now==0;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    int pos=0;
    rep(i,n)if(s[i]==')'){pos=i;break;}
    if(pos>0){
        memcpy(t,s,sizeof s);
        for(int i=pos;i<n;++i)t[i]=t[i+1];
            t[n]=')';
        if(check()){puts("Yes");return 0;}
    }
    pos=0;
    rep(i,n)if(s[i]=='('){pos=i;}
    if(pos>0){
        memcpy(t,s,sizeof s);
        for(int i=pos-1;i>0;--i)t[i+1]=t[i];
        t[1]='(';
        if(check()){puts("Yes");return 0;}
    }
    puts("No");
    return 0;
}