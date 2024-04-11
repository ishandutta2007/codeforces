#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        printf("%d\n",N);
        for (int i=1;i<=N;i++) {
            printf("%d%c",i," \n"[i==N]);
        }
    }
}