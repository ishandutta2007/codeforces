#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int A[1010], anst, ans=1234567890;

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<=100; i++){
        int sum = 0;
        for (int j=1; j<=N; j++) sum += min(min(abs(i-A[j]-1), abs(i-A[j]+1)), abs(i-A[j]));
        if (ans > sum){
            anst = i;
            ans = sum;
        }
    }
    printf("%d %d\n", anst, ans);
    return 0;
}