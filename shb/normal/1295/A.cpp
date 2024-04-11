#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        for (int i=1;i<=N/2;i++) {
            if (i == 1 && N % 2 == 1) 
                printf("7");
            else 
                printf("1");
        }
        puts("");
    }
}