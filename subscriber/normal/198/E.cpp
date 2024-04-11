#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

pair<long long,int>inf=mp(9000000000000000000ll,0);
pair<pt,pair<int,long long> >q[333333];
int e[333333],x0,Y0,q1,q2,ans,u[333333],n,x,y;
pair<long long,int>s[1999999];

void init(int pos,int l,int r){
	if (l==r){
		s[pos]=mp(q[l].S.S,l);
		return;
	}
	init(pos+pos,l,(l+r)/2);
	init(pos+pos+1,(l+r)/2+1,r);
	s[pos]=min(s[pos+pos],s[pos+pos+1]);
}

void deel(int pos,int l,int r,int v){
	if (v<l||v>r)return;
	if (l==r){
		s[pos]=mp(9000000000000000000ll,0);
		return;
	}
	deel(pos+pos,l,(l+r)/2,v);
	deel(pos+pos+1,(l+r)/2+1,r,v);
	s[pos]=min(s[pos+pos],s[pos+pos+1]);
}

pair<long long,int>find(int pos,int l,int r,int v){
	if (v<l)return inf;
	if (v>=r)return s[pos];
	return min(find(pos+pos,l,(l+r)/2,v),find(pos+pos+1,(l+r)/2+1,r,v));
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> x0 >> Y0 >> q[0].F.S >> q[0].S.F >> n;
	q[0].F.F=0;
	q[0].S.S=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&x,&y,&q[i].F.F,&q[i].F.S,&q[i].S.F);
		q[i].S.S=(x0-x)*1ll*(x0-x)+(Y0-y)*1ll*(Y0-y);
	}
	sort(q,q+n+1);
	for (int i=0;i<=n;i++)e[i]=q[i].F.F;
	init(1,0,n+1);
	deel(1,0,n+1,0);
	q1=0;
	q2=1;
	u[0]=0;
	while (q1<q2){
		int x=upper_bound(e,e+n+1,q[u[q1]].F.S)-e-1;
		long long r=q[u[q1]].S.F;
		r*=r;
		pair<long long,int>ee=find(1,0,n+1,x);
		while(ee.F<=r){
			ans++;
			u[q2++]=ee.S;
			deel(1,0,n+1,ee.S);
			ee=find(1,0,n+1,x);
		}
		q1++;
	}
	CC(ans);
	return 0;
}