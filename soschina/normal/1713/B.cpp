#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long maxa = 0, suma = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            maxa = max(maxa, 1ll * a[i]);
            if(a[i] > a[i - 1])
                suma += a[i] - a[i - 1];
        }
        puts(maxa == suma ? "YES" : "NO");
    }
	return 0;
}