#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
const int N = 1e6+10;

int n,ans,top = 1;
char c[N];

inline int check(int n){
	int sum = 0;
	for(int i=1;i <= n;i++)
		sum += c[i] == '(' ? 1 : -1;
	return !sum;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",c+1);
	if(!check(n)){
		puts("-1");
		return 0;
	}
	while(top <= n){
		if(c[top] == '('){
			int sum = 1;
			top++;
			while(sum)
				sum += (c[top++] == '(') ? 1 : -1;
		}
		else{
			int sum = -1,las = top;
			top++;
			while(sum)
				sum += (c[top++] == '(') ? 1 : -1;
			ans += top-las;
		}
	}
	printf("%d\n",ans);
	return 0;
}