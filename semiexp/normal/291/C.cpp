#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long i64;

int K, N;
i64 ips[100000];
i64 tmp[100000];

i64 ip()
{
	int a, b, c, d;
	scanf("%d.%d.%d.%d", &a, &b, &c, &d);
	return ((i64)a << 24LL) | ((i64)b << 16LL) | ((i64)c << 8LL) | d;
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;i++) ips[i] = ip();

	for(int i=1;i<=31;i++){
		i64 mask = ((i64)1<<(i64)i)-1;
		mask <<= 32-i;
		for(int j=0;j<N;j++) tmp[j] = ips[j] & mask;
		sort(tmp, tmp+N);

		int cnt = 1;
		for(int j=1;j<N;j++) if(tmp[j] != tmp[j-1]) ++cnt;

		if(cnt==K){
			printf("%I64d.%I64d.%I64d.%I64d\n", (mask>>24), (mask>>16)&255, (mask>>8)&255, mask&255);
			return 0;
		}
	}
	puts("-1");
	return 0;
}