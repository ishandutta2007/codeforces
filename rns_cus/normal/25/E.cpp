#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
#define N 100010

int p[5][5], len[5], t, tot, x[N];
char s[3][N];

int calc(string s, string t){
    int S = s.size(), T = t.size();
    int i, j;
    for(i=0, j=0; i<S;){
        if(s[i] == t[j]){
            i ++; j ++;
            if(j == T) return T;
        }
        else{
            j ? j = x[j] : i ++;
        }
    }
    return j;
}

void kmp(int a, int b, int c){
    string t = s[c];
    int T = t.size();
    memset(x, 0, sizeof x);
   // for(int i = 0; i < 20; i ++) printf("%d ", x[i]); puts("");
    for(int i=1, j=0; i<T;)t[i]==t[j] ? i++,j++,x[i]=j : j ? j=x[j] : i++;
    p[a][c] = calc(s[a], s[c]);   p[b][c] = calc(s[b], s[c]);
    //printf("%d %d\n", p[a][c], p[b][c]);
}

int main(){
   // freopen("e.in", "r", stdin);
    for(int i = 0; i < 3; i ++){ gets(s[i]); len[i] = strlen(s[i]); }
    kmp(0, 1, 2);
    kmp(1, 2, 0);
    kmp(0, 2, 1);
    int ans = len[0] + len[1] + len[2];
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++) if(i!=j){
            t = 3 - i - j;
            if(p[i][j] == len[j]) tot = len[i] + len[t] - p[i][t];
            else tot = len[i] + len[j] + len[t] - p[i][j] - p[j][t];
            if(tot < ans) ans = tot;
        }
    }
    printf("%d\n", ans);
}