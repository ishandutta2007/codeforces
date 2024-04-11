#include<stdio.h>
#include<math.h>
#include<memory.h>
#define M 200

int prime[M];
int isPrime(int x)
{
	for(int i = 2; i <= sqrt(x); i++)
		if(x % i == 0) return 0;
	return 1;
}
int work()
{
	int k = 0;
	memset(prime,0,sizeof(prime));

	for(int i = 2; i<= 1000; i++)
	if(isPrime(i) == 1){
		prime[k] = i;
    k ++;
	}
	return k--;
}
int main()
{
	int n,k,cnt = 0,m,p;
	scanf("%d%d",&n,&p);
	k = work();
		for(int i = 0; prime[i] + prime[i+1] + 1 <= n ; i++){
				m = prime[i]+prime[i+1]+1;
	      if(isPrime(m) == 1) cnt++;
		}
		if(cnt>=p) printf("YES\n");
	else printf("NO\n");
	return 0;
}