#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5+10;

int n,c[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++)
		scanf("%d",&c[i]);
	for(int j=30;j >= 0;j--){
		int t = 1 << j,cnt = 0;
		for(int i=1;i <= n;i++)
			if(c[i]&t) cnt++;
		if(cnt == 1){
			for(int i=1;i <= n;i++)
				if(c[i]&t)
					printf("%d ",c[i]);
			for(int i=1;i <= n;i++)
				if(!(c[i]&t))
					printf("%d ",c[i]);
			puts("");
			return 0;
		}
	}
	for(int i=1;i <= n;i++)
		printf("%d ",c[i]);
	puts("");
	return 0; 
	return 0;
}