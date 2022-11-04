#include <cstdio>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
const int N = 3e5 + 1;

int exgcd(int a, int b, long long &x, long long &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    long long z = x;
    x = y, y = z - y * (a / b);
    return d;
}


int n, m, a, b, x, y;
long long c[N], sum = 0;

int main(){
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &a, &b);
        c[i] = a - b;
        if(c[i] > 0)
            cnt++;
        sum += b;
    }
    sort(c + 1, c + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++)
        c[i] += c[i - 1];
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &a, &b);
        long long x = 0, y = 0;
        int d = exgcd(a, b, x, y);
        if(n % d){
            puts("-1");
            continue;
        }
        x *= n / d;
        y *= n / d;
        if(x < 0){
            long long tmp = (-x - 1) / (b / d) + 1;
            x += tmp * (b / d);
            y -= tmp * (a / d);
        }
        if(y < 0){
            long long tmp = (-y - 1) / (a / d) + 1;
            x -= tmp * (b / d);
            y += tmp * (a / d);
        }
        if(x < 0 || y < 0){
            puts("-1");
            continue;
        }
        long long tmp = x / (b / d);
        x -= tmp * (b / d);
        y += tmp * (a / d);
        long long diff = cnt - x * a;
        long long ans = sum + c[x * a];
        if(diff > 0){
            long long tmp = diff / a / (b / d);
            x += tmp * (b / d);
            y -= tmp * (a / d);
            ans = max(ans, sum + c[x * a]);
            x += b / d;
            y -= a / d;
            if(y >= 0)
                ans = max(ans, sum + c[x * a]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}