#include<cstdio>
#include<map>
#include<cstring>
using namespace std;

map<long long,int> A[27];
int val[27];
long long Ans,sum[100000+19];
char s[100000+19];

int main()
{
	for (int i=0;i<26;i++) scanf("%d",&val[i]);
	scanf("%s",s);
	int Len=strlen(s);
	for (int i=1;i<=Len;i++)
		sum[i]=sum[i-1]+val[s[i-1]-'a'],
		Ans+=A[s[i-1]-'a'][sum[i-1]],
		A[s[i-1]-'a'][sum[i]]++;
	printf("%I64d\n",Ans);
}