#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
#define DIV 998244353
#define MAX_N 1000000

int N;
ll ans=0;
ll pac[MAX_N+1];



int main(){
    scanf("%d", &N);
    pac[1]=1;
    for(int i=2; i<=N; i++){
        pac[i]=(pac[i-1]*i)%DIV;
    }
    ans = (pac[N]*(ll)N)%DIV;
    ll minus = 1;
    for(int i=1; i<N; i++){
        minus = (minus * (N-i+1))%DIV;
        ans = (ans + DIV - minus)%DIV;
    }
    printf("%lld", ans);
    return 0;
}