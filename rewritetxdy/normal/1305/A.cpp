#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 110;

int t,n,x[110],y[110];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++) scanf("%d",&x[i]);
		for(int i=1;i <= n;i++) scanf("%d",&y[i]);
		sort(x+1,x+1+n);
		sort(y+1,y+1+n);
		for(int i=1;i <= n;i++) printf("%d ",x[i]);
		puts("");
		for(int i=1;i <= n;i++) printf("%d ",y[i]);
		puts("");
	}
}