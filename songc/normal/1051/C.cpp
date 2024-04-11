#include <bits/stdc++.h>
using namespace std;

int N;
int A[110];
int cnt[110], An, Bn;
int nice, k, u;

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        cnt[A[i]]++;
    }
    for (int i=1; i<=100; i++) {
        if (cnt[i] == 1) nice++;
        if (cnt[i] >= 3) k = i;
    }
    if (nice & 1){
        if (k == 0){
            puts("NO");
            return 0;
        }
    }
    else k = 0;

    puts("YES");
    for (int i=1; i<=N; i++){
        if (A[i] == k){
            if (u == 1) {
                printf("A");
                continue;
            }
            if (u == 2) {
                printf("B");
                continue;
            }

            if (An < Bn) {
                printf("A");
                An++;
                u = 2;
            }
            else {
                printf("B");
                Bn++;
                u = 1;
            }
        }
        else if (cnt[A[i]] == 1) {
            if (An < Bn) {
                printf("A");
                An++;
            }
            else {
                printf("B");
                Bn++;
            }
        }
        else printf("A");
    }
    return 0;
}