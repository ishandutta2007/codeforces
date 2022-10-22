#include <bits/stdc++.h>
using namespace std;

int N;
int cnt[1010];
int P[1010];

deque<int> Q;

int main(){
    int a, b;
    scanf("%d", &N);
    for (int i=1; i<N; i++){
        scanf("%d %d", &a, &b);
        if (b != N) {
            puts("NO");
            return 0;
        }
        cnt[a]++;
    }

    for (int i=1; i<=N; i++){
        if (cnt[i]){
            if ((int)Q.size() < cnt[i] - 1){
                puts("NO");
                return 0;
            }
            int p = N, t;
            for (int j=1; j<cnt[i]; j++){
                t = Q.front();
                Q.pop_front();
                P[t] = p;
                p = t;
            }
            P[i] = p;
        }
        else Q.push_back(i);
    }

    puts("YES");
    for (int i=1; i<N; i++) printf("%d %d\n", i, P[i]);
    return 0;
}