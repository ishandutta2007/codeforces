#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
double M;
double A[1010], B[1010];

bool chk(double k){
    double mass = M + k;
    for (int i=2; i<=N; i++){
        mass -= mass / A[i-1];
        mass -= mass / B[i];
    }
    mass -= mass / A[N];
    mass -= mass / B[1];
    return mass >= M;
}

int main(){
    scanf("%d %lf", &N, &M);
    for (int i=1; i<=N; i++) scanf("%lf", &A[i]);
    for (int i=1; i<=N; i++) scanf("%lf", &B[i]);
    double L=0, H=1e13;
    for (int i=1; i<=200; i++){
        double mid = (L+H)/2;
        if (chk(mid)) H = mid;
        else L = mid;
    }
    if (chk(L+1)) printf("%.10lf\n", L);
    else puts("-1");
    return 0;
}