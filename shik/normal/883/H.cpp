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
int cnt[128],odd;
vector<char>an[SIZE],an2[SIZE];
bool good(int num,int N){
    int len=N/num;
    if(len%2==0){
        if(odd)return 0;
        int it=0;
        REP(i,128){
            while(cnt[i]){
                cnt[i]-=2;
                an[it].PB(i);
                an2[it].PB(i);
                if(SZ(an[it])+SZ(an2[it])>=len)it++;
            }
        }
    }
    else{
        if(num<odd)return 0;
        if((num-odd)%2)return 0;
        int it=0;
        vector<char>center(num);
        REP(i,128){
            if(cnt[i]&1){
                cnt[i]--;
                center[it++]=i;
            }
        }
        int it2=0;
        REP(i,128){
            while(cnt[i]>0){
                if(it<num){
                    cnt[i]--;
                    center[it++]=i;
                }
                else{
                    cnt[i]-=2;
                    while(SZ(an[it2])+SZ(an2[it2])+1>=len)it2++;
                    an[it2].PB(i);
                    an2[it2].PB(i);
                }
            }
        }
        REP(i,num)an[i].PB(center[i]);
    }
    printf("%d\n",num);
    REP(i,num){
        REP(j,SZ(an[i]))printf("%c",an[i][j]);
        for(int j=SZ(an2[i])-1;j>=0;j--)printf("%c",an2[i][j]);
        puts("");
    }
    return 1;
}
int main(){
    DRI(N);
    RS(s);
    REP(i,N)cnt[(int)s[i]]++;
    REP(i,128){
        if(cnt[i]&1)odd++;
    }
    REPP(i,1,N+1){
        if(N%i==0&&good(i,N))return 0;
    }
    return 0;
}