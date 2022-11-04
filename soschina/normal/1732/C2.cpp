#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int t, n, q, a[N], x[N];
long long s[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            x[i] = x[i - 1] ^ a[i];
            s[i] = s[i - 1] + a[i];
        }
        while(q--){
            int L, R;
            scanf("%d%d", &L, &R);
            long long sum = (s[R] - s[L - 1]) - (x[R] ^ x[L - 1]);
            if(sum == 0){
                printf("%d %d\n", L, L);
                continue;
            }
            int l = L, r = R;
            while((x[r] ^ x[l - 1]) == (x[r] ^ x[l]) + a[l])
                l++;
            while((x[r] ^ x[l - 1]) == (x[r - 1] ^ x[l - 1]) + a[r])
                r--;
            int ansl = l, ansr = r;
            l--;
            while(l >= L){
                while((x[r] ^ x[l - 1]) == (x[r - 1] ^ x[l - 1]) + a[r])
                    r--;
                if(r - l < ansr - ansl)
                    ansl = l, ansr = r;
                l--;
            }
            printf("%d %d\n", ansl, ansr);
        }
    }
	return 0;
}