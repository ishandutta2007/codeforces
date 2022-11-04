#include <cstdio>
#include <iostream>
using namespace std;

int t, n, h, m;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &h, &m);
        int sleep = h * 60 + m;
        int ans = 0x7fffffff;
        while(n--){
            scanf("%d%d", &h, &m);
            int alarm = h * 60 + m;
            if(sleep <= alarm)
                ans = min(ans, alarm - sleep);
            else
                ans = min(ans, alarm - sleep + 1440);
        }
        h = ans / 60;
        m = ans % 60;
        printf("%d %d\n", h, m);
    }
    return 0;
}