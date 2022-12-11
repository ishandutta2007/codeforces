#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,ans,sum;
int a[1010];

int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	fd(i,n,1){
		sum+=a[i];
		if (sum>=m){
			ans=n-i+1;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}