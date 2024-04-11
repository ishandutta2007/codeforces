#include <bits/stdc++.h>
#define ERASE 222
#define INSERT 111
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;

int N;
struct smith {
    LL a,b,t;
}s[200010];

int M = 0;
struct event {
    LL t;
    int tp,num;
}e[400010];
LL sucmin[400010];

bool cmp1(event e1, event e2) {
    return e1.t < e2.t;
}

const LL INF = 1e18;

int main() {
    scanf("%d",&N);
    LL ans = 0;
    for (int i=1;i<=N;i++) {
        scanf("%lld%lld%lld",&s[i].a, &s[i].b, &s[i].t);
        e[++M] = (event){s[i].a, INSERT, i};
        e[++M] = (event){s[i].b, ERASE, i}; 
    }
    sort(e+1,e+M+1,cmp1);
    sucmin[M + 1] = INF;
    for (int i=M;i>=1;i--) {
        sucmin[i] = sucmin[i + 1];
        if (e[i].tp == INSERT) {
            sucmin[i] = min(sucmin[i], s[e[i].num].a + s[e[i].num].t);
        }
    }
    /*
    for (int i=1;i<=M;i++) {
        printf("%d %d %d\n",e[i].t,e[i].tp,s[e[i].num].t);
    }
    */
    multiset<pair<LL,int> >nt;
    LL nowT = 0;
    int L = 0;
    while(L < M) {
        L++;
        int R = L;
        LL T = e[R].t;
        while(R + 1 <= M && e[R + 1].t == T) {
            R++;
        }
        //printf("calc %d %d\n",L,R);
        //printf("begin nowT = %lld\n",nowT);
        if (nt.empty()) {
            nowT = max(nowT,T);
            //printf("skip to %lld\n",nowT);
        } else {
            LL minT = (*nt.begin()).first;
            //printf("mt = %lld \n",minT);
            LL delta = T - nowT;
            ans += delta / minT;
            nowT += delta / minT * minT;
            //printf("%lld-%lld += %lld delta = %lld\n",nowT - delta / minT * minT, nowT, delta/minT,delta);
        }
    
        /*
        for (int i=L;i<=R;i++) {
            if (e[i].tp == ERASE) {
                nt.erase(nt.find(pli(s[e[i].num].t, e[i].num)));
            }
        }
        */

        while(!nt.empty() && nowT + (*nt.begin()).first > s[(*nt.begin()).second].b) {
            nt.erase(nt.begin());
        }
        if (!nt.empty() && nowT + (*nt.begin()).first <= sucmin[L]) {
            ans++;
            nowT = nowT + (*nt.begin()).first;
        } else {
            nowT = max(nowT,T);
        }
        //printf("%lld %lld\n",ans,nowT);
        for (int i=L;i<=R;i++) {
            if (e[i].tp == INSERT) {
                nt.insert(pli(s[e[i].num].t, e[i].num));
            }
        }
        L = R;
    }
    printf("%lld\n",ans);
}