// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,ans=0,now=0,cnt=0;
	vector<int> lst;
	char s[20000];
	scanf("%d",&n); while ( getchar()!='\n' );
	gets(s);
	for ( int i=0; s[i]; i++ ) {
		if ( now==0 && s[i]==' ' ) continue;
		now++;
		if ( s[i]=='.' || s[i]=='?' || s[i]=='!' ) {
			lst.push_back(now);
			now=0;
		}
	}
	if ( now>0 ) lst.push_back(now);
	for ( int i=0; i<(int)lst.size(); i++ )
		if ( lst[i]>n ) {
			puts("Impossible");
			return 0;
		}
	now=cnt=0;
	for ( int i=0; i<(int)lst.size(); i++ ) {
		if ( now+(cnt>0)+lst[i]>n ) now=cnt=0,ans++;
		now+=(cnt>0)+lst[i];
		cnt++;
	}
	if ( now>0 ) ans++;
	printf("%d\n",ans);
	return 0;
}