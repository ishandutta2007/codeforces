#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int P[]={999999937,999999929,999999893,999999883,999999797};
bool tp;
char s[1000005];
int ans1,ans2,n;

struct hash
{
	int p,bin[1000005],sum[1000005];
	void prepare(int x)
	{
		p=x,bin[0]=1;
		rep(i,1,n) bin[i]=(LL)bin[i-1]*10%p,sum[i]=((LL)sum[i-1]*10+s[i]-48)%p;
	}
	bool jdg(int p1,int p2,int len2,int len3)
	{
		int a=sum[p1],b=(sum[p2]-(LL)sum[p1]*bin[len2])%p,c=(sum[n]-(LL)sum[p2]*bin[len3])%p;
		return a=(a+b+p)%p,c=(c+p)%p,a==c;
	}
} t[5];

void prepare()
{
	rep(i,0,4) t[i].prepare(P[i]);
}

bool jdg(int p1,int p2)
{
	ans1=p1,ans2=p2;
	int len1=p1,len2=p2-p1,len3=n-p2;
	if(!len1 || !len2 || !len3) return 0;
	if(len1>1 && s[1]=='0' || len2>1 && s[p1+1]=='0' || len3>1 && s[p2+1]=='0') return 0;
	rep(i,0,4)
		if(!t[i].jdg(p1,p2,len2,len3))
			return 0;
	return 1;
}

bool jdg(int p)
{
	int len=n-p;
	if(jdg(len,p)) return 1;
	if(jdg(len-1,p)) return 1;
	if(jdg(p-len,p)) return 1;
	if(jdg(p-len+1,p)) return 1;
	return 0;
}

void PRT()
{
	rep(i,1,n)
	{
		printf("%c",s[i]);
		if(i==ans1) printf("+");
		if(i==ans2) printf("=");
	}
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	int p1=n/3,p2=n/2,l=n-p2,r=n-p1;
	for(prepare(); l<=r; tp^=1)
	{
		if(tp)
		{
			if(jdg(l++))
			{
				PRT();
				break;
			}
		}
		else
		{
			if(jdg(r--))
			{
				PRT();
				break;
			}
		}
	}
	return 0;
}