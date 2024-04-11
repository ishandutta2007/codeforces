#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char str[MAXN];
bool valid[MAXN];
bool vowel(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y') return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	memset(valid,true,sizeof(valid));
	for(int i=0;i<n-1;i++)
	{
		if(vowel(str[i])&&vowel(str[i+1]))
		{
			for(int j=i+1;j<n-1;j++)
				str[j]=str[j+1];
			n--;
			i--;
		}
	}
	str[n]='\0';
	printf("%s\n",str);
	return 0;
}