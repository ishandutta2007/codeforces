#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 100005
#define ll long long
using namespace std;

ll ans;
ll c[maxn];
int n,m;
ll sum,sum1;
bool bz[maxn];

int main(){
	scanf("%d",&n);
	fo(i,1,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) sum++;
		if (x<y) sum1++;
	}
	if (sum>sum1) puts("Mishka");
	else if (sum<sum1) puts("Chris");
	else puts("Friendship is magic!^^");
	return 0;
}