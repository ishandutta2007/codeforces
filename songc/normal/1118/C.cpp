#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
int ans[50][50];
int cnt[1010];

int main(){
    int a;
    scanf("%d", &N);
    for (int i=1; i<=N*N; i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int i=1; i<=1000; i++){
        if (!cnt[i]) continue;
        if (N&1){
            if (cnt[i] >= 4){
                bool tf = true;
                for (int j=1; j<=N/2 && tf; j++){
                    for (int k=1; k<=N/2; k++){
                        if (ans[j][k]) continue;
                        ans[j][k] = i;
                        ans[N-j+1][k] = i;
                        ans[j][N-k+1] = i;
                        ans[N-j+1][N-k+1] = i;
                        tf = false;
                        break;
                    }
                }
                if (!tf) {
                    cnt[i] -= 4;
                    i--;
                    continue;
                }
            }
            if (cnt[i] >= 2){
                bool tf = true;
                for (int j=1; j<=N/2 && tf; j++){
                    if (ans[N/2+1][j]) continue;
                    ans[N/2+1][j] = i;
                    ans[N/2+1][N-j+1] = i;
                    tf = false;
                }
                for (int j=1; j<=N/2 && tf; j++){
                    if (ans[j][N/2+1]) continue;
                    ans[j][N/2+1] = i;
                    ans[N-j+1][N/2+1] = i;
                    tf = false;
                }
                cnt[i] -= 2;
                if (tf){
                    puts("NO");
                    return 0;
                }
            }
            if (cnt[i] & 1){
                if (ans[N/2+1][N/2+1]){
                    puts("NO");
                    return 0;
                }
                ans[N/2+1][N/2+1] = i;
                cnt[i]--;
            }
        }
        else{
            if (cnt[i]%4){
                puts("NO");
                return 0;
            }
            bool tf = true;
            for (int j=1; j<=N/2 && tf; j++){
                for (int k=1; k<=N/2; k++){
                    if (ans[j][k]) continue;
                    ans[j][k] = i;
                    ans[N-j+1][k] = i;
                    ans[j][N-k+1] = i;
                    ans[N-j+1][N-k+1] = i;
                    tf = false;
                    break;
                }
            }
            cnt[i] -= 4;
        }
        i--;
    }
    puts("YES");
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}