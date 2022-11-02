// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	int id,len,pos;
	P(){}
	P( int _id, int _len, int _pos ):id(_id),len(_len),pos(_pos){}
} p[N];
bool operator <( P a, P b ) { return a.pos<b.pos; }
int main()
{
	int L,b,f,n,op,x,cnt=0,idx=0;
	scanf("%d%d%d%d",&L,&b,&f,&n);
	while ( n-- ) {
		scanf("%d%d",&op,&x);
		if ( op==1 ) {
			int flg=0;
			if ( cnt==0 ) {
				if ( x<=L ) {
					p[cnt++]=P(++idx,x,0);
					flg=1;
				}
			} else if ( p[0].pos>=x+f ) {
				p[cnt++]=P(++idx,x,0);
				flg=1;
			} else {
				for ( int i=1; i<cnt; i++ ) if ( p[i].pos-p[i-1].pos-p[i-1].len>=b+f+x ) {
					flg=1;
					p[cnt++]=P(++idx,x,p[i-1].pos+p[i-1].len+b);
					break;
				}
				if ( !flg && L-p[cnt-1].pos-p[cnt-1].len>=x+b) {
					flg=1;
					p[cnt]=P(++idx,x,p[cnt-1].pos+p[cnt-1].len+b);
					cnt++;
				}
			} 
			if ( flg ) printf("%d\n",p[cnt-1].pos);
			else idx++,puts("-1");
		} else {
			idx++;
			for ( int i=0; i<cnt; i++ ) if ( p[i].id==x ) swap(p[i],p[cnt-1]);
			cnt--;
		}
		sort(p,p+cnt);
	}
	return 0;
}