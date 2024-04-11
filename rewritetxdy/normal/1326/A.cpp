#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;

int t,n;
stack<int>q;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n == 1){
			puts("-1");
			continue;
		}
		q.push(3),q.push(4);
		for(int i=3;i <= n;i++)
			i&1 ? q.push(4) : q.push(2);
		while(!q.empty())
			printf("%d",q.top()) , q.pop();
		puts("");
	}
}