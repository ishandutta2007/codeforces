#include <cstdio>
using namespace std;

int t, a, b, d;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &a, &b, &d);
        long long x = a | b;
        int s = 0;
        while(d % 2 == 0)
            d >>= 1, s++;
        bool flag = true;
        for (int i = 0; i < s; i++)
            if((x >> i) & 1)
                flag = false;
        if(!flag){
            puts("-1");
            continue;
        }
        long long now = 0;
        for (int i = s; (1 << i) <= x; i++)
            if(((now >> i) & 1) ^ ((x >> i) & 1))
                now += (long long)d << i;
        printf("%lld\n", now);
    }
	return 0;
}