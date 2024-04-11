#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <map>
typedef long long LL;

const int MAXN=505;
const LL MOD=998244353;
int n,sizb,sizc;
LL a[MAXN],b[MAXN],c[MAXN];
bool fac[MAXN];
std::map<LL,int> mp;

inline LL gcd(LL x,LL y){
    if(!x||!y) return x+y;
    while(y){
        std::swap(x,y);
        y%=x;
    }
    return x;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        if(a[i]==1) n--,i--;
    }
    for(int i=1;i<=n;i++){
        LL sq=sqrt(a[i])+0.5;
        if(sq*sq==a[i]){
            fac[i]=1;
            LL sqsq=sqrt(sq)+0.5;
            if(sqsq*sqsq==sq){
                if(mp.find(sqsq)!=mp.end()) mp[sqsq]=mp[sqsq]+4;
                else mp[sqsq]=4;
                continue;
            }
            if(mp.find(sq)!=mp.end()) mp[sq]=mp[sq]+2;
            else mp[sq]=2;
            continue;
        }
        LL cb=cbrt(a[i])+0.5;
        if(cb*cb*cb==a[i]){
            fac[i]=1;
            if(mp.find(cb)!=mp.end()) mp[cb]=mp[cb]+3;
            else mp[cb]=3;
            continue;
        }
        //b[++sizb]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]) continue;
            LL d=gcd(a[i],a[j]);
            if(d==1) continue;
            if(!fac[i]){
                if(mp.find(d)!=mp.end()) mp[d]=mp[d]+1;
                else mp[d]=1;
                LL e=a[i]/d;
                if(mp.find(e)!=mp.end()) mp[e]=mp[e]+1;
                else mp[e]=1;
                fac[i]=1;
            }
            if(!fac[j]){
                if(mp.find(d)!=mp.end()) mp[d]=mp[d]+1;
                else mp[d]=1;
                LL e=a[j]/d;
                if(mp.find(e)!=mp.end()) mp[e]=mp[e]+1;
                else mp[e]=1;
                fac[j]=1;
            }
        }
        if(!fac[i]) c[++sizc]=a[i];
    }
    std::sort(c+1,c+sizc+1);
    LL ans=1;
    for(auto it:mp) ans=ans*(it.second+1)%MOD;
    int temp=0;
    for(int i=1;i<=sizc;i++){
        if(i==1||c[i]==c[i-1]) temp++;
        else{
            ans=ans*(temp+1)%MOD*(temp+1)%MOD;
            temp=1;
        }
    }
    ans=ans*(temp+1)%MOD*(temp+1)%MOD;
    printf("%I64d\n",ans);
    return 0;
}