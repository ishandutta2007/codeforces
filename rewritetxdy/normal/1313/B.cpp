#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

int t,n,x,y;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&x,&y);
		printf("%d %d\n",max(1,(min(x+y-n+1,n))),min(x+y-1,n));
	}
} 
//3 1 3 12 23