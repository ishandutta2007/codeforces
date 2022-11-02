#include<stdio.h>
#include<algorithm>
using namespace std;
int gcd(int a, int b){return  !b?a:gcd(b, a % b);}
int main(){
    int a,b;
    while(scanf("%d%d", &a, &b) ==2){
        int ans = (7-max(a, b));
        if(!ans){puts("0/1");continue;}
        if(ans == 6){puts("1/1");continue;}
        int d = gcd(6, ans);
        printf("%d/%d\n", ans/d, 6/d);
    }
}