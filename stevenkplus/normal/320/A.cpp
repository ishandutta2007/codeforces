#include<cstdio>

#define du(x) scanf("%d" ,&x)
bool s(int S){
    return S==0?1:((S%100== 14&&s(S/10/10))|| S%1000==144&&s(S/10/10/10)||S %10== 1&& s(S/10));
}
 main(){ int d;
du(d), printf(s(d)?"YES\n":"NO\n"); }