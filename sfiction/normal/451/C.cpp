/*
ID: Sfiction
OJ: CF
PROB: 451C
*/
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int cas;
	long long n,k,d1,d2;

	scanf("%d",&cas);
	while (cas--){
		cin>>n>>k>>d1>>d2;
		if (n%3){
			puts("no");
			continue;
		}
		n/=3;

		long long a[3]={0};
		bool flag=false;
		for (int i=0;i<4;++i){
			a[1] = i & 1 ? d1 : -d1;
			a[2] = a[1] + (i & 2 ? d2 : -d2);
			long long t=k-a[1]-a[2];
			if (t%3)
				continue;
			a[0]=t/3;
			a[1]+=a[0];
			a[2]+=a[0];
			if (0<=a[0] && a[0]<=n
				&& 0<=a[1] && a[1]<=n
				&& 0<=a[2] && a[2]<=n)
				flag=true;
		}
		puts(flag ? "yes" : "no");
	}
	return 0;
}