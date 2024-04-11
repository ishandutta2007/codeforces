#include <bits/stdc++.h>
using namespace std;

int N, C;
int arr[202020];
bool chk[202020];

int main() {
    int k;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &arr[i]);
    C=1;
    for (int i=1; i<N; i++){
        scanf("%1d", &k);
        chk[arr[i]] = true;
        if (!k) {
            for (int j=C; j<=i; j++) {
                if (!chk[j]){
                    puts("NO");
                    return 0;
                }
            }
            C = i+1;
        }
    }
    chk[arr[N]] = true;
    for (int j=C; j<=N; j++) {
        if (!chk[j]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}