// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
using namespace std;
vector<pair<int,int> > ans;
int n,num[N],lst[N],srt[N],vis[N],lp;
bool cp( int a, int b ) {
	if ( num[a]!=num[b] ) return num[a]<num[b];
	return a<b;
}
bool done() {
	for ( int i=1; i<n; i++ )
		if ( num[i]>num[i+1] ) return 0;
	return 1;
}
bool is_lucky( int x ) { return x==0?1:(x%10==4||x%10==7)&&is_lucky(x/10); }
bool unlucky() {
	for ( int i=1; i<=n; i++ )
		if ( is_lucky(num[i]) ) return 0;
	return 1;
}
void SWAP( int a, int b ) {
	ans.push_back(make_pair(a,b));
	swap(num[a],num[b]);
}
int get_lp() {
	for ( int i=1; i<=n; i++ )
		if ( srt[i]==i && is_lucky(num[i]) ) return i;
	for ( int i=1; i<=n; i++ )
		if ( is_lucky(num[i]) ) {
			//puts("XD");
			for ( int j=1; j<=n; j++ ) num[j]=srt[j];
			SWAP(i,srt[i]);
			return srt[i];
		}
	puts("QQ");
	return 0;
}
void build() {
	for ( int i=1; i<=n; i++ ) lst[i]=i;
	sort(lst+1,lst+n+1,cp);
	for ( int i=1; i<=n; i++ ) srt[lst[i]]=i;
}
void solve( int p ) {
	SWAP(p,lp);
	int q=p;
	while ( srt[q]!=p ) {
		vis[p]=1;
		SWAP(p,lst[p]);
		p=lst[p];
	}
	SWAP(p,lp);
	vis[p]=1;
}
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",num+i);
	if ( done() ) { puts("0"); return 0; }
	if ( unlucky() ) { puts("-1"); return 0; }
	build(); lp=get_lp(); build();
	//printf("lp = %d\n",lp);
	//for ( int i=1; i<=n; i++ ) printf("%d: %d,%d,%d\n",i,num[i],lst[i],srt[i]);
	for ( int i=1; i<=n; i++ ) {
		//printf("i = %d\n",i);
		if ( vis[i] || srt[i]==i ) continue;
		solve(i);
		//for ( int j=1; j<=n; j++ ) printf("%d%c",num[j],j==n?'\n':' ');
	}
	printf("%d\n",(int)ans.size());
	for ( int i=0; i<(int)ans.size(); i++ ) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}