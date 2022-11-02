#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;
typedef long long ll;

int n,m,k,cnt;

//1:RDU 2:L

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(4*n*m-2*n-2*m < k){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(m == 1){
		if(k <= n-1){
			puts("1");
			printf("%d D\n",k);
		}
		else{
			puts("2");
			printf("%d D\n",n-1);
			printf("%d U\n",k-n+1);
		}
		return 0;
	}
	int kk = k,x = 1;
	while(k && x < n){
		cnt++; 
		if(k <= 3*(m-1)){
			if(k%3 && k > 3) cnt++;
			break;
		}
		k -= 3*(m-1);
		
		cnt++;
		if(k <= m-1)
			break;
		k -= m-1;
		
		cnt++;
		if(k <= 1)
			break;
		k--;
		
		x++;
	}
	if(k && x == n){
		cnt++;
		if(k > m-1)
			cnt++;
		if(k > 2*(m-1))
			cnt++;
	}
	printf("%d\n",cnt);
	
	k = kk,x = 1;
	while(k && x < n){
		if(k <= 3*(m-1)){
			if(k >= 3)
				printf("%d RDU\n",k/3);
			if(k%3 >= 1)
				printf("1 R");
			if(k%3 >= 2)
				printf("D");
			puts("");
			break;
		}
		printf("%d RDU\n",m-1);
		k -= 3*(m-1);
		
		if(k <= m-1){
			printf("%d L\n",k);
			break;
		}
		printf("%d L\n",m-1);
		k -= m-1;
		
		
		if(k <= 1){
			printf("1 D\n");
			break;
		}
		printf("1 D\n");
		k--;
		
		x++;
	}
	if(k && x == n){
		if(k <= m-1)
			printf("%d R\n",k);
		else{
			printf("%d R\n",m-1);
			k -= m-1;
			
			if(k <= m-1)
				printf("%d L\n",k);
			else{
				printf("%d L\n",m-1);
				k -= m-1;
				printf("%d U\n",k);
			}
		}
	}
	return 0;
}