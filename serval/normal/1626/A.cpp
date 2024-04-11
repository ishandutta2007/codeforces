#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int T;
char s[N];
int cnt[26];
void solve()
{
	scanf("%s",s+1);
	for (int i=0;i<26;i++)
		cnt[i]=0;
	for (int i=1;s[i];i++)
		cnt[s[i]-'a']++;
	for (int i=0;i<26;i++)
		if (cnt[i]==2)
			printf("%c",'a'+i);
	for (int i=0;i<26;i++)
		if (cnt[i]==1)
			printf("%c",'a'+i);
	for (int i=0;i<26;i++)
		if (cnt[i]==2)
			printf("%c",'a'+i);
	printf("\n");
}
int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}