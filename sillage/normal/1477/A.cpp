#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	int T;
    cin >> T;
	while(T--){
        int n;
        long long k, g;
        scanf("%d%lld", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        sort(a + 1, a + n + 1);
		g = a[2] - a[1];
		for (int i = 2; i <= n - 1; i++) g = __gcd(g, a[i + 1] - a[i]);
		int p;
        for (p = 1; p <= n; p++)
		    if(!((a[p] - k) % g)){
                break; 
            }
		puts(p>n?"NO":"YES");
	}
	return 0;
}