#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e6+19;
char s1[Maxn],s2[Maxn];
int a,b;

int main()
{
	scanf("%s%s",s1,s2);
	int L1=strlen(s1),L2=strlen(s2);
	if (L1!=L2) {puts("NO");return 0;}
	if (s1==s2) {puts("YES");return 0;}
	for (int i=0;i<L1;i++)
		a|=(s1[i]=='1'),b|=(s2[i]=='1');
	if (a^b) puts("NO");else puts("YES");
}