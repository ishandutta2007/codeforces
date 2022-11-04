#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 2;

int t, n;
char s[2][N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < 2; i++)
            scanf("%s", s[i] + 1);
        int ans = 0, l = n, r = 1, last = -1;
        for (int i = 1; i <= n; i++)
            if(s[0][i] == '*' || s[1][i] == '*'){
                l = min(l, i);
                r = max(r, i);
                if(s[0][i] == '*' && s[1][i] == '*'){
                    ans++;
                    last = -1;
                }else if(last == -1){
                    last = s[1][i] == '*';
                }else if((s[1][i] == '*') ^ last){
                    ans++;
                    last = -1;
                }
            }
        printf("%d\n", r - l + ans);
    }
    return 0;
}