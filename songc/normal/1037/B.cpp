#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[202020];
long long ans;

int main(){
    scanf("%d %d", &N, &S);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    for (int i=0; i<N/2; i++) ans += max(0, arr[i]-S);
    ans += abs(S - arr[N/2]);
    for (int i=N/2+1; i<N; i++) ans += max(0, S-arr[i]);
    printf("%I64d", ans);
    return 0;
}