// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define N 110
#define PB push_back
#define SZ(x) ((int)(x).size())
using namespace std;
typedef vector<int> VI;
typedef long long LL;
map<string,int> id;
struct B {
	string name;
	int t; LL w,h,brd,spa;
	VI pak;
	B( string _name="", int _t=0, LL _w=0, LL _h=0 ):name(_name),t(_t),w(_w),h(_h){ brd=spa=0; }
	void pack( string s ) {
		pak.PB(id[s]);
	}
	void set_brd( int x ) {
		brd=x;
	}
	void set_spa( int x ) {
		spa=x;
	}
} b[N];
bool cp( B x, B y ) { return x.name < y.name; }
int n;
int vis[N];
void go( int p ) {
	if ( vis[p] ) return;
	vis[p]=1;
	if ( b[p].t==1 ) return;
	if ( b[p].pak.empty() ) {
		b[p].w=b[p].h=0;
		return;
	}
	for ( int i=0; i<SZ(b[p].pak); i++ ) go(b[p].pak[i]);
	if ( b[p].t==2 ) {
		LL max_h=0,sum_w=0;
		for ( int i=0; i<SZ(b[p].pak); i++ ) {
			B &c=b[b[p].pak[i]];
			max_h=max(max_h,c.h);
			sum_w+=c.w;
		}
		b[p].w=sum_w+(SZ(b[p].pak)-1)*b[p].spa+2*b[p].brd;
		b[p].h=max_h+2*b[p].brd;
	} else if ( b[p].t==3 ) {
		LL max_w=0,sum_h=0;
		for ( int i=0; i<SZ(b[p].pak); i++ ) {
			B &c=b[b[p].pak[i]];
			max_w=max(max_w,c.w);
			sum_h+=c.h;
		}
		b[p].h=sum_h+(SZ(b[p].pak)-1)*b[p].spa+2*b[p].brd;
		b[p].w=max_w+2*b[p].brd;
	} else puts("QQ");
}
int main()
{
	char s1[N],s2[N],s3[N];
	int m,w,h,x;
	scanf("%d",&m);
	while ( m-- ) {
		scanf(" %[a-zA-Z]",s1);
		if ( strcmp(s1,"Widget")==0 ) {
			scanf(" %[a-z](%d,%d)",s2,&w,&h);
			id[s2]=n;
			b[n]=B(s2,1,w,h);
			n++;
		} else if ( strcmp(s1,"HBox")==0 ) {
			scanf("%s",s2);
			id[s2]=n;
			b[n]=B(s2,2);
			n++;
		} else if ( strcmp(s1,"VBox")==0 ) {
			scanf("%s",s2);
			id[s2]=n;
			b[n]=B(s2,3);
			n++;
		} else {
			scanf(".%[^(]",s2);
			if ( strcmp(s2,"pack")==0 ) {
				scanf("(%[^)])",s3);
				b[id[s1]].pack(s3);
			} else if ( strcmp(s2,"set_border")==0 ) {
				scanf("(%d)",&x);
				b[id[s1]].set_brd(x);
			} else if ( strcmp(s2,"set_spacing")==0 ) {
				scanf("(%d)",&x);
				b[id[s1]].set_spa(x);
			} else puts("QQ");
		} 
	}
	memset(vis,0,sizeof(vis));
	for ( int i=0; i<n; i++ ) go(i);
	sort(b,b+n,cp);
	for ( int i=0; i<n; i++ ) printf("%s %I64d %I64d\n",b[i].name.c_str(),b[i].w,b[i].h);
	return 0;
}