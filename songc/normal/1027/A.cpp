#include <bits/stdc++.h>
using namespace std;

int TC, N;
char str[1010];

int main(){
    scanf("%d", &TC);
    for (int tc=0; tc<TC; tc++){
        scanf("%d", &N);
        scanf("%s", str+1);
        bool tf = true;
        for (int i=1; i<=N; i++){
            if (str[i] == str[N-i+1]) continue;
            if (abs(str[i] - str[N-i+1]) == 2) continue;
            tf = false;
        }
        puts(tf ? "YES" : "NO");
    }
    return 0;
}