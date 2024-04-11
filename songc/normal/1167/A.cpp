#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int TC, N;
char A[110];

int main(){
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);
        for (int i=1; i<=N; i++) scanf(" %c", &A[i]);
        bool tf = true;
        for (int i=1; i<=N-10; i++) {
            if (A[i] == '8'){
                tf = false;
                puts("YES");
                break;
            }
        }
        if (tf) puts("NO");
    }
    return 0;
}