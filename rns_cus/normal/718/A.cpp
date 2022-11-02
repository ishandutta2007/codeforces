#include<bits/stdc++.h>
using namespace std;

#define N 2000200

int n, k, cur, tot, pos, cnt;
char s[N];

int main(){
    //freopen("a.in", "r", stdin);
    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for(int i = 0; i < n; i ++){
        if(s[i] == '.'){ cur = i; break; }
    }
   // printf("%d\n", cur);
    pos = 0;
    for(int i = cur + 1; i < n; i ++){
        if(s[i] >= '5'){ pos = i; break; }
    }
    if(pos == 0){ puts(s); return 0; }
    cnt = 1;
    for(int i = pos - 1; i > cur; i --){
        if(s[i] == '4') cnt ++;
        else break;
    }
    cnt = min(cnt, k);
   // printf("CNT  %d\n", cnt);

    tot = 1;
    n = pos - cnt;
    if(n == cur) n --;
    //printf("NN %d\n", n);
    for(int i = n; i >= 0; i --){
        if(i == cur) continue;
        tot += s[i] - '0';
        s[i] = tot % 10 + '0';
        tot /= 10;
    }
    if(tot) printf("1");
    for(int i = 0; i <= n; i ++){
        printf("%c", s[i]);
    }puts("");
}