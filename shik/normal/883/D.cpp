#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[SIZE];
int mon[SIZE],mn,p[SIZE],pn;
int dp[SIZE];
int wa[SIZE];
int BIT[SIZE];
void ins(int x,int v){
    for(;x;x-=x&-x)BIT[x]+=v;
}
int qq(int x){
    int res=0;
    int y=x-1;
    for(;x<SIZE;x+=x&-x)res+=BIT[x];
    if(y){
        for(;y<SIZE;y+=y&-y)res-=BIT[x];
    }
    return res;
}
bool valid(int len){
    MS0(dp);
    MS0(BIT);
    MS0(wa);
    dp[0]=1;
    REP(i,pn+1){
        if(dp[i]){
            int it=upper_bound(mon+1,mon+mn+1,p[i]+len)-mon;
            if(it>mn)return 1;
            if(i<pn){
                if(p[i+1]<mon[it])dp[i+1]=1;
                else{
                    int it2=upper_bound(p,p+pn+1,mon[it]+len)-p-1;
                    if(it2==i+1)wa[i+1]=1;
                    else if(it2>i+1){
                        ins(it2,1);
                        ins(i+1,-1);
                    }
                }
            }
        }
        if(wa[i]){
            int it=upper_bound(mon+1,mon+mn+1,p[i])-mon;
            if(it>mn)return 1;
            if(i<pn){
                if(p[i+1]<mon[it])dp[i+1]=1;
                else{
                    int it2=upper_bound(p,p+pn+1,mon[it]+len)-p-1;
                    if(it2==i+1)wa[i+1]=1;
                    else if(it2>i+1){
                        ins(it2,1);
                        ins(i+1,-1);
                    }
                }
            }
        }
        if(i&&qq(i)){
            int it=upper_bound(mon+1,mon+mn+1,max(p[i],p[i-1]+len))-mon;
            if(it>mn)return 1;
            if(i<pn){
                if(p[i+1]<mon[it])dp[i+1]=1;
                else{
                    int it2=upper_bound(p,p+pn+1,mon[it]+len)-p-1;
                    if(it2==i+1)wa[i+1]=1;
                    else if(it2>i+1){
                        ins(it2,1);
                        ins(i+1,-1);
                    }
                }
            }
        }
    }
    return 0;
}
int main(){
    DRI(n);
    RS(s);
    p[0]=-MOD;
    REP(i,n){
        if(s[i]=='*')mon[++mn]=i;
        else if(s[i]=='P')p[++pn]=i;
    }
    if(pn==1){
        int v1=0,v2=0;
        REPP(i,1,mn+1){
            if(mon[i]<p[1])v1++;
            else v2++;
        }
        printf("%d ",max(v1,v2));
        if(v1>v2||(v1==v2&&p[1]-mon[1]<mon[mn]-p[1])){
            printf("%d\n",p[1]-mon[1]);
        }
        else{
            printf("%d\n",mon[mn]-p[1]);
        }
        return 0;
    }
    printf("%d ",mn);
    int ll=1,rr=n;
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(valid(mm))rr=mm;
        else ll=mm+1;
    }
    REPP(i,1,mn+1)mon[i]=n+1-mon[i];
    reverse(mon+1,mon+mn+1);
    reverse(p+1,p+pn+1);
    REPP(i,1,pn+1)p[i]=n+1-p[i];
    int ll2=1,rr2=n;
    while(ll2<rr2){
        int mm=(ll2+rr2)/2;
        if(valid(mm))rr2=mm;
        else ll2=mm+1;
    }
    printf("%d\n",min(ll,ll2));
    return 0;
}