// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <climits>
using namespace std;
int e[7][7];
map<string,int> idx;
int exps[3],cnt[3],t[7],ans_1,ans_2;
void go( int p ) {
	if ( p==7 ) {
		int sml=INT_MAX,big=0;
		for ( int i=0; i<3; i++ ) {
			if ( cnt[i]==0 ) return;
			int tmp=exps[i]/cnt[i];
			sml=min(sml,tmp);
			big=max(big,tmp);
		}
		int diff=big-sml,like=0;
		for ( int i=0; i<7; i++ )
			for ( int j=0; j<7; j++ )
				if ( e[i][j] && t[i]==t[j] ) like++;
		if ( diff<ans_1 || (diff==ans_1&&like>ans_2) ) {
			ans_1=diff;
			ans_2=like;
		}
		return;
	}
	for ( int i=0; i<3; i++ ) {
		t[p]=i;
		cnt[i]++;
		go(p+1);
		cnt[i]--;
	}
}
int main()
{
	string hero[]={"amazon","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"};
	for ( int i=0; i<7; i++ ) idx[hero[i]]=i;
	int m; char a[20],b[20];
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%s %*s %s",a,b);
		e[idx[a]][idx[b]]=1;
	}
	for ( int i=0; i<3; i++ ) scanf("%d",exps+i);
	ans_1=INT_MAX;
	go(0);
	printf("%d %d\n",ans_1,ans_2);
	return 0;
}