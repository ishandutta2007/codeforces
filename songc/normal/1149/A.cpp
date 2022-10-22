#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int O, T;

int main(){
    int a;
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &a);
        if (a==1) O++;
        else T++;
    }
    if (O == N){
        for (int i=1; i<=N; i++) printf("1 ");
        return 0;
    }
    if (T == N){
        for (int i=1; i<=N; i++) printf("2 ");
        return 0;
    }
    printf("2 1 ");
    O--, T--;
    while(T--) printf("2 ");
    while(O--) printf("1 ");
    return 0;
}