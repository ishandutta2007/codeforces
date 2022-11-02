#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3e3+10;

int n,m,t,c[N],q[N][N],top[N],sum;

int main()
{
	scanf("%d%d",&n,&m);
	char ch;
	for(int i=1;i <= n;i++) 
		scanf(" %c",&ch) , c[i] = ch == 'L' ? 0 : 1;
	for(int k=1;k <= n;k++){
		for(int i=1;i < n;i++)
			if(c[i] && !c[i+1])
				swap(c[i],c[i+1]) , q[k][++top[k]] = i , i++;
		if(!top[k]) break;
		sum += top[k] , t = k;
	}
	if(m < t || m > sum){
		puts("-1");
		return 0;
	}
	for(int i=1;i <= t;i++){
		if(sum-top[i] > m-1){
			printf("%d ",top[i]);
			for(int j=1;j <= top[i];j++)
				printf("%d ",q[i][j]);
			puts("");
			sum -= top[i] , m--;
			continue;
		}
		if(sum == m)
			for(int j=1;j <= top[i];j++)
				printf("1 %d\n",q[i][j]);
		else{
			printf("%d ",sum-m+1);
			for(int j=1;j <= sum-m+1;j++)
				printf("%d ",q[i][j]);
			puts("");
			for(int j=sum-m+2;j <= top[i];j++)
				printf("1 %d\n",q[i][j]);
			sum = m;
		}
	}
}