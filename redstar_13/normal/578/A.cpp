#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b) {cout<<-1<<endl;return 0;}
	if(b==0) {printf("%.10lf",(double)a/100);return 0;}
	if(a%b==0 and (a/b)%2==1) {printf("%.10lf",(double)b);return 0;}
	double x1=(a-b);
	double x2=(a+b);
	int i=x1/b;
	int j=x2/b;
	if(i%2) i--;
	if(j%2) j--;
	double d1=x1/(double)i;
	double d2=x2/(double)j;
	double k=min(d1,d2);
	printf("%.10lf",k);
	return 0;
}