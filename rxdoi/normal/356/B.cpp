#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int Maxn=1e6+19;
typedef long long LL;
int cnt[Maxn][26];
char s1[Maxn],s2[Maxn];
LL n,m,Len,tmp,_gcd;

inline LL gcd(LL a,LL b) {return b==0?a:gcd(b,a%b);}
inline LL lcm(LL a,LL b) {return a/gcd(a,b)*b;}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	scanf("%s%s",s1,s2);
	Len=1LL*strlen(s1)*n;
	_gcd=gcd(strlen(s1),strlen(s2));
	for (int i=0;i<strlen(s1);i++) cnt[i%_gcd][s1[i]-'a']++;
	for (int i=0;i<strlen(s2);i++) tmp+=cnt[i%_gcd][s2[i]-'a'];
	printf("%I64d\n",Len-tmp*(Len/lcm(strlen(s1),strlen(s2))));
}