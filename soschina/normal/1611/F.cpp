#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, s, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &s);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        long long now = 0;
        int ll = 1, rr = 0;
        int l = 1;
        for (int r = 1; r <= n; r++){
            now += a[r];
            while(now + s < 0)
                now -= a[l++];
            if(r - l > rr - ll)
                rr = r, ll = l;
        }
        if(rr - ll < 0)
            puts("-1");
        else
            printf("%d %d\n", ll, rr);
    }
    return 0;
}