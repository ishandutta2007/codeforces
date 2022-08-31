#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckyzx
#define y0 fuckyxc
#define x1 fuckxzc
#define y1 fucxyzc
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,MOD1=500000003,MOD2=700000001,G1=53,G2=97;
const ld eps=1e-12;
char s[N],t[N];
int n,m,ans,fir,cnt[2],cha[26],tmp[N][26];
ll cl[26],h1[N],f1[N],h2[N],f2[N];
pair<int,int> get(int x,int y){
    return mp((h1[y]-1ll*h1[x]*f1[y-x]%MOD1+MOD1)%MOD1,(h2[y]-1ll*h2[x]*f2[y-x]%MOD2+MOD2)%MOD2);
}
bool check(int l0,int l1){
    int ptr=0;
    rep(i,n)if(s[i]=='0'){
        if(get(1,l0)!=get(ptr+1,ptr+l0))return 0;
        else ptr+=l0;
    }else{
        if(get((fir-1)*l0+1,(fir-1)*l0+l1)!=get(ptr+1,ptr+l1))return 0;
        else ptr+=l1;
    }
    return 1;
}
int main(){
    scanf("%s",s+1),scanf("%s",t+1);
    n=strlen(s+1),m=strlen(t+1);
    rep(i,m)h1[i]=(1ll*h1[i-1]*G1+(t[i]-'a'+2))%MOD1;
    f1[0]=1;rep(i,m)f1[i]=1ll*f1[i-1]*G1%MOD1;
    rep(i,m)h2[i]=(1ll*h2[i-1]*G2+(t[i]-'a'+5))%MOD2;
    f2[0]=1;rep(i,m)f2[i]=1ll*f2[i-1]*G2%MOD2;
    if(s[1]=='1')rep(i,n)s[i]=s[i]=='1'?'0':'1';
    rep(i,n)++cnt[s[i]-'0'];
    fir=-1;
    rep(i,n)if(s[i]=='1'){fir=i;break;}
    rep(i,m)++cha[t[i]-'a'];
    rep(i,m){
        memcpy(tmp[i],tmp[i-1],sizeof(tmp[i]));
        ++tmp[i][t[i]-'a'];
    }
    rep(i,m){
        //printf("%d\n",i);
        memset(cl,0,sizeof cl);
        for(int j=0;j<26;++j)cl[j]+=1ll*tmp[i][j]*cnt[0];
        ll k=m-1ll*cnt[0]*i;
        if(fir!=-1){
            if(k<=0)continue;
            if(k%cnt[1]!=0)continue;
            k/=cnt[1];
            for(int j=0;j<26;++j)cl[j]+=1ll*(tmp[(fir-1)*i+k][j]-tmp[(fir-1)*i][j])*cnt[1];
        }
        bool flag=1;
        for(int j=0;j<26;++j)if(cha[j]!=cl[j]){flag=0;break;}
        if(!flag)continue;
        if(i==k){
            flag=1;
            rep(j,i)if(t[j]!=t[(fir-1)*i+j]){flag=0;break;}
            if(flag)continue;
        }
        if(check(i,(int)k))++ans;
    }
    printf("%d\n",ans);
    return 0;
}