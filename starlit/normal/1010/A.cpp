#include<bits/stdc++.h>
#define N 1003
using namespace std;
int n,m,a[N],b[N];
double s;
inline void cal(int x){
	if(x==1){puts("-1");exit(0);}
	s=s*x/(x-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	s=m;cal(b[1]);
	for(int i=n;i;i--){
		cal(a[i]);
		if(i>1)cal(b[i]);
	}
	printf("%.6f",s-m);
}
/*
2
12
11 8
7 5

*/