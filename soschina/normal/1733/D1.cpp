#include <cstdio>
#include <iostream>
using namespace std;
const int N = 5002;

int T, n, x, y;
bool a[N];
char s[N], t[N];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%s%s", &n, &x, &y, s + 1, t + 1);
        int cnt = 0, pos1 = 0, pos2 = 0;
        for (int i = 1; i <= n; i++){
            a[i] = s[i] != t[i];
            cnt += a[i];
            if(a[i]){
                if(pos1)
                    pos2 = i;
                else
                    pos1 = i;
            }
        }
        if(cnt & 1){
            puts("-1");
            continue;
        }
        if(y <= x){
            if(cnt == 2 && pos1 + 1 == pos2)
                printf("%d\n", min(y * 2, x));
            else
                printf("%lld\n", (long long)(cnt >> 1) * y);
        }
    }
    return 0;
}