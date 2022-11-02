#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,n,sum,x; 

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int cnt = 0;
		sum = 0;
		for(int i=1;i <= n;i++){
			scanf("%d",&x);
			if(!x)
				cnt++ , sum++;
			else
				sum += x;
		}
		if(!sum) cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}