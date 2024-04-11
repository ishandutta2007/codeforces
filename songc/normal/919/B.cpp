#include <bits/stdc++.h>
using namespace std;

int N;

int digitsum(int k){
    if (k <= 0) return 0;
    return digitsum(k/10) + k%10;
}

int main(){
    int k, cnt;
    scanf("%d", &N);
    for (k=0,cnt=0; cnt<N; k++) if (digitsum(k) == 10) cnt++;
    printf("%d", k-1);
    return 0;
}