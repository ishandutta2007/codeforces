#include <cstdio>
#define Maxn 200005
#define Inf (9223372036854775807LL)

int n , k , a[Maxn] , len[Maxn];
long long ans;

int main(){
	scanf("%d%d" , &n , &k);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &a[i]);
	len[n + 1] = 0;
	for(int i = n ; i >= 1 ; i--)
		if(a[i] == 1)
			len[i] = len[i + 1] + 1;
		else
			len[i] = 0;
	for(int i = 1 ; i <= n ; i++){
		long long mul = 1 , sum = 0;
		for(int j = i ; j <= n ; j++)
			if(a[j] == 1){
				if(mul % k == 0 && 1 <= mul / k - sum && mul / k - sum <= len[j])
					ans++;
				sum += len[j];
				j += len[j] - 1;
			}else{
				if(mul >= Inf / a[j])
					break;	
				mul *= a[j];
				sum += a[j];
				if(mul == sum * k)
					ans++;
			}
	}
	printf("%I64d\n" , ans);
	return 0;
}

// By Sooke.
// CF992D Nastya and a Game.