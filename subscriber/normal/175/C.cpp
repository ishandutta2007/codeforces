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

int n,x,y,m;
pair<long long,long long>q[1111];
long long w,l,p[1111],ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> q[i].S >> q[i].F;
	sort(q,q+n);
	cin >> m;
	for (int i=0;i<m;i++)cin >> p[i];
	p[m]=1e15;
	x=0;
	y=0;
	w=0;
	for(;;){
		l=min(q[x].S,p[y]-w);
		ans+=l*q[x].F*(y+1);
		q[x].S-=l;
		if (!q[x].S)x++;
		if (x==n)break;
		w+=l;
		if (p[y]==w)y++;
	}
	CC(ans);
	return 0;
}