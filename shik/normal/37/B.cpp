// by shik
#include <cstdio>
#include <algorithm>
#include <queue>
#define N 1010
using namespace std;
struct R {
	int id,pow,dmg;
	void read( int _id ) { id=_id; scanf("%d%d",&pow,&dmg); }	
	bool chk( int hp, int max_hp ) {
		//pow/100 >= hp/max_hp
		return max_hp*pow>=100*hp;
	}
} r[N];
bool cp_pow( R a, R b ) { return a.pow>b.pow; }
bool operator <( const R &a, const R &b ) { return a.dmg<b.dmg; }
priority_queue<R> q;
int sol[1000010];
int main()
{
	int n,max_hp,hp,reg,tot=0,i,sec=0,cnt=0;
	scanf("%d%d%d",&n,&max_hp,&reg);
	for ( i=0; i<n; i++ ) r[i].read(i+1);
	sort(r,r+n,cp_pow);
	i=0; hp=max_hp;
	while ( hp>0 && sec<1000000 ) {
		hp-=tot;
		hp=min(hp+reg,max_hp);
		while ( i<n && r[i].chk(hp,max_hp) ) {
			q.push(r[i]);
			i++;
		}
		if ( hp<=0 ) break;
		if ( !q.empty() ) {
			tot+=q.top().dmg;
			sol[sec]=q.top().id;
			cnt++;
			q.pop();
		}
		sec++;
	}
	if ( hp>0 ) puts("NO");
	else {
		puts("YES");
		printf("%d %d\n",sec,cnt);
		for ( i=0; i<1000000; i++ )
			if ( sol[i] ) printf("%d %d\n",i,sol[i]);	
	}
	return 0;
}