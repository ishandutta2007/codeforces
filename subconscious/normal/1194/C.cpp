#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long double ld;
const int N=105;
int q,slen,tlen,plen,cnt[26];
char s[N],t[N],p[N];
int main(){
    
    for(scanf("%d",&q);q--;){
        bool flag=1;
        scanf("%s%s%s",s,t,p);
        slen=strlen(s),tlen=strlen(t),plen=strlen(p);
        int cur=0;
        rep(i,slen){
            while(cur<tlen&&s[i]!=t[cur])++cur;
            if(cur==tlen){flag=0;break;}
            ++cur;
        }
        rep(i,26)cnt[i]=0;
        rep(i,slen)++cnt[s[i]-'a'];
        rep(i,tlen)--cnt[t[i]-'a'];
        rep(i,plen)++cnt[p[i]-'a'];
        rep(i,26)if(cnt[i]<0){flag=0;break;}
        puts(flag?"YES":"NO");
    }

    return 0;
}