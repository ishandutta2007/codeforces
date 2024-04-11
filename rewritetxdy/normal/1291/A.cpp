#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,n;
char c[3333];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++)
			scanf(" %c",&c[i]);
		while(n && !(c[n]&1)) n--;
		if(n <= 1){
			puts("-1");
			continue;
		}
		int sum = 1,flag = 0,cnt = 0;
		for(int i=1;i < n;i++){
			sum += c[i];
			if(c[i]&1)
				flag = 1;
			if(c[i] != '0')
				cnt++;
		}
		if(sum&1 && (!flag || cnt <= 1))
			puts("-1");
		else{
			for(int i=1;i <= n;i++)
				if(sum&1 && c[i]&1 && flag){
					flag = 0;
					while(c[i+1] == '0') i++;
				}
				else
					printf("%c",c[i]);
			puts("");
		}
	}
	return 0;
}