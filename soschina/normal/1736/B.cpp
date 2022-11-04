#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int t, n, a[N], b[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        b[0] = a[1], b[n] = a[n];
        for (int i = 1; i < n; i++)
            b[i] = a[i] * a[i + 1] / gcd(a[i], a[i + 1]);
        bool flag = true;
        for (int i = 0; i < n; i++)
            if(gcd(b[i], b[i + 1]) != a[i + 1])
                flag = false;
        puts(flag ? "YES" : "NO");
    }
	return 0;
}