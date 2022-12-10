#include<cstdio>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1e5+19,P=1e9+7;
char s[N];
int k,L,Ans;

int Pow(int a,int b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}

int main()
{
	scanf("%s%d",s,&k);L=strlen(s);
	For(i,0,L)
		if (s[i]=='0'||s[i]=='5')
			(Ans+=1LL*(Pow(2,(1LL*k*L+i)%(P-1)+P-1)-Pow(2,i)+P)%P*Pow((Pow(2,L)-1+P)%P,P-2)%P)%=P;
	printf("%d\n",Ans);
}