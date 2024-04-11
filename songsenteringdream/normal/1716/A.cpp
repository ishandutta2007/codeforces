#include<cstdio>
using namespace std;
int T,n,ans[6]={0,1,1,1,2,2};
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",(n==1?2:(n/6*2+ans[n%6])))) scanf("%d",&n);
	return 0;
}