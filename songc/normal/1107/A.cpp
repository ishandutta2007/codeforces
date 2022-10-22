#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int TC, N;
int arr[330];

int main(){
    scanf("%d", &TC);
    while (TC--){
        scanf("%d", &N);
        for (int i=1; i<=N; i++) scanf("%1d", &arr[i]);
        if (N == 2 && arr[1] >= arr[2]){
            puts("NO");
            continue;
        }
        puts("YES");
        printf("2\n%d ", arr[1]);
        for (int i=2; i<=N; i++) printf("%d", arr[i]);
        printf("\n");
    }
    return 0;
}