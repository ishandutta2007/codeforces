#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 5000011

typedef pair <int, int> pii;
priority_queue <pii> q;

char s[N];

int main(){
    scanf("%s", s);
    int len = strlen(s);
    int del = 0;
    long long ans = 0;

    for(int i=0; i<len; i++){
        if(s[i] == '(') del ++;
        else if(s[i] == ')') del --;
        else {
            int a, b;
            scanf("%d %d", &a, &b);
            s[i] = ')';
            ans += b;
            del --;
            q.push(pii(b-a, i));
        }

        if(del < 0){
            if(q.empty()) break;
            pii p = q.top(); q.pop();
            ans -= p.first;
            del += 2;
            s[p.second] = '(';
        }
    }

    if(del != 0) {puts("-1"); return 0;}
    printf("%I64d\n", ans);
    puts(s);
}