#include<bits/stdc++.h>
using namespace std;
int n , phi[2200] , vis[2200] , pr[2200] , tot;
int main()
{
	for(register long long i = 2 ; i <= 2000 ; i++ )
	{
		if(!vis[i]) pr[++tot] = i , phi[i] = i - 1;
		for(register long long j = 1 ; j <= tot && i * pr[j] <= 2000 ; j++ )
		{
			vis[i * pr[j]] = 1;
			if(i % pr[j] == 0)
			{
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			}
			phi[i * pr[j]] = phi[i] * phi[pr[j]];
		}
	}
	phi[1] = 1;
	scanf("%d" , &n);
	printf("%d\n" , phi[phi[n]]);
	return 0;
}