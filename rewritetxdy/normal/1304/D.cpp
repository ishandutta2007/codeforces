#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 2e5+10;

int t,n,c[N],b[N],ans[N],top;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		char ch;
		int cnt = 0;
		for(int i=1;i < n;i++)
			scanf(" %c",&ch) , b[i] = ch == '<' , cnt += b[i];
		cnt++;
		int x = 1,las = 0,k=0,cur = n-cnt;
		for(;x <= n;){
			while(!b[x] && x < n) x++;
			ans[++top] = n-k , k++;
//			printf("%d ",n-k) , k++;
			for(int i=1;i <= x-las-1;i++)
				ans[++top] = cur--;
//				printf("%d ",cur--);
			las = x , x++;
		}
		for(int i=1;i < n;i++){
			int l = i;
			while(b[i] && ans[i] > ans[i+1] && i < n) i++;
			if(i > l)
				sort(ans+l,ans+1+i);
		}
		for(int i=1;i <= n;i++)
			printf("%d ",ans[i]);
		puts("");
		x = 1,las = 0,cur = 1;
		while(x <= n){
			while(!b[x] && x < n) x++;
			cur += x-las;
			for(int i=1;i <= x-las;i++)
				printf("%d ",cur-i);
			las = x , x++;
		}
		puts("");
		for(int i=1;i <= n;i++)
			ans[i] = b[i] = 0;
		top = 0;

	}
}