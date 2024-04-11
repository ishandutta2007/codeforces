#include <cstdio>
using namespace std;
const int N=300005;
char s[N];
char t[N];
int cnt[N],cur;
int ans;
int main()
{
	scanf("%s",s+1);
	for (int i=1;s[i];i++)
	{
		if (s[i]!=s[i-1])
			cur++;
		t[cur]=s[i];
		cnt[cur]++;
	}
	ans=cnt[(cur+1)>>1]+1;
	if ((cur&1)^1)
		ans=0;
	for (int i=1;i<=(cur>>1);i++)
		if (cnt[i]+cnt[cur+1-i]<3||t[i]!=t[cur+1-i])
			ans=0;
	printf("%d\n",ans>=3?ans:0);
	return 0;
}