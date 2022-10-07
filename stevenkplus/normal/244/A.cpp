 #include <cstdio>
 #include <iostream>

 using namespace std;
 
 const int MAXN = 50*50;
 bool taken[MAXN];
 int want[MAXN];
 int N, K;
 int main() {
     scanf("%d %d", &N, &K);
     for(int i = 0; i < K; ++i) {
         int p;
         scanf("%d", &p);
         want[i] = p;
         taken[p] = true;
    }
    for(int i = 0; i < K; ++i) {
        int p = want[i];
        int cnt = 1;
        printf("%d", p);
        for(int j = 1; cnt < N; ++j) {
            if (!taken[j]) {
                taken[j] = true;
                printf(" %d", j);
                cnt++;
            }
       }
       printf("\n");
    }
    return 0;
 }