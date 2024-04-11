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
#define sz size
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << x << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long ull;

int n,kk=0,yy[222222],pp[222222],zz[222222],xx[222222],g[222222],s[222222],x,y,z;
long long ans=0;

bool lu(int x){
	while (x){
		if (x%10!=4&&x%10!=7)return 0;
		x/=10;
	}
	return 1;
}

void rec(int x){
	s[x]=1;
	g[x]=0;
	for (int w=xx[x];w;w=pp[w])if (!s[yy[w]]){
		rec(yy[w]);
		s[x]+=s[yy[w]];
		if (zz[w])g[x]+=s[yy[w]];else g[x]+=g[yy[w]];
	}
}

void recc(int x,int ss,int gg){
	int t=g[x]+gg;
	ans+=t*1ll*(t-1);
	int ns=ss+1,gs=gg;
	for (int w=xx[x];w;w=pp[w])if (s[yy[w]]<s[x]){
		ns+=s[yy[w]];
		if (zz[w])gs+=s[yy[w]];else gs+=g[yy[w]];
	}
	for (int w=xx[x];w;w=pp[w])if (s[yy[w]]<s[x]){
		if (zz[w])recc(yy[w],ns-s[yy[w]],ns-s[yy[w]]);else recc(yy[w],ns-s[yy[w]],gs-g[yy[w]]);
	}
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		yy[++kk]=y;
		zz[kk]=lu(z);
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		zz[kk]=lu(z);
		pp[kk]=xx[y];
		xx[y]=kk;
	}
	rec(0);
	recc(0,0,0);
	cout << ans << endl;
	return 0;
}