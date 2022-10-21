#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n,q,a,b;
char c;
map<int, int> mpU,mpL;

int main(){
    scanf("%d%d", &n, &q);
    mpU[0] = 0, mpL[0] = 0;
    while(q--) {
        scanf("%d%d", &a, &b);
        getchar();
        scanf("%c", &c);
        auto itL = mpL.lower_bound(b);
        auto itU = mpU.lower_bound(a);
        if((itU != mpU.end() && itU -> first == a) || (itL != mpL.end() && itL -> first == b)){
            printf("0\n");
            continue;
        }
        if(c == 'U'){
            itL--;
            if(itU == mpU.end() || itL->first >= (n+1 - itU->first)){
                mpU[a] = b - (itL -> first);
                printf("%d\n", b - (itL->first));
            }
            else{
                int res = (itU->first) - a + (itU->second);
                mpU[a] = res;
                printf("%d\n", res);
            }
        }
        else{
            itU--;
            if(itL == mpL.end() || itU->first >= (n+1 - itL->first)){
                mpL[b] = a - (itU -> first);
                printf("%d\n", a - (itU->first));
            }
            else{
                int res = (itL->first) - b + (itL->second);
                mpL[b] = res;
                printf("%d\n", res);
            }
        }
    }
}