#include<cstdio>
#define M 1000000007LL
using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	long long tmp,ans=1;
	tmp=((long long)a*(a+1)/2)%M*(long long)b;
	tmp%=M;
	tmp+=(long long)a;tmp%=M;
	ans=tmp;
	tmp=((long long)b*(b-1)/2)%M;
	ans*=tmp;ans%=M;
	printf("%d\n",(int)ans);
	return 0;
}