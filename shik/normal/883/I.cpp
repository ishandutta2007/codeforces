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
const int SIZE = 3e5+10;
int BIT[SIZE];
void ins(int x){
    x+=2;
    for(;x<SIZE;x+=x&-x)BIT[x]++;
}
int qq(int x){
    x+=2;
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
int get(int ll,int rr){
    if(ll>rr)return 0;
    if(!ll)return qq(rr);
    return qq(rr)-qq(ll-1);
}
int main(){
    DRII(N,K);
    VI a(N+1);
    REP(i,N)RI(a[i+1]);
    sort(a.begin()+1,a.end());
    int ll=0,rr=MOD;
    while(ll<rr){
        int mm=(ll+rr)/2;
        MS0(BIT);
        int lt=1,res=-1;
        ins(0);
        REPP(i,1,N+1){
            while(a[i]-a[lt]>mm)lt++;
            res=get(lt-1,i-K);
            if(res>0)ins(i);
        }
        if(res<=0)ll=mm+1;
        else rr=mm;
    }
    printf("%d\n",ll);
    return 0;
}