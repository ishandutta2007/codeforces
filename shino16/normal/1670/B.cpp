//https://codeforces.com/contest/1670/submission/157107779
#include<cstdio>
#include<cstring>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, a, b) for (int i = (int)a; i < (int)(b); i++)
#define rrep2(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
bool inc[26];
int main(){
    int total_testcases;
    scanf("%d", &total_testcases);
    for (int testcase_i = 1; testcase_i <= total_testcases; testcase_i++){
        int N;
        scanf("%d", &N);
        char S[N+1];
        scanf("\n%s", S);
        int K;
        scanf("%d", &K);
        char T[K];
        rep(i, K){
            scanf(" %c", T + i);
            inc[T[i] - 'a'] = true;
        }
        int now = 0, answer = 0;
        rep(i, N) if(inc[S[i] - 'a']){
            chmax(answer, i - now);
            now = i;
        }
        printf("%d\n", answer);
        rep(i, K) inc[T[i] - 'a'] = false;
    }
}