#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;

const int N = 200020;

int n,c[N],maxn,a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i <= n;i++){
		a[i] = c[i]+maxn , maxn = max(maxn,a[i]);
		printf("%d ",a[i]);
	}
}