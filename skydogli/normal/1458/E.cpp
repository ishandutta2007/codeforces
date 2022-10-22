#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define MN 100005
set<pii >S;
int n,m,a[MN],b[MN],x[MN],y[MN];
map<pii,bool>GG,ok;
int main(){
    
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		if(!GG[mp(a[i],b[i])]){
			GG[mp(a[i],b[i])]=1;
			x[i]=y[i]=i;
		}
	}
	sort(x+1,x+1+n,[](int x,int y){return a[x]<a[y];});
	sort(y+1,y+1+n,[](int x,int y){return b[x]<b[y];});
	int p=1,q=1;
	int X=0,Y=0;
	while(p<=n&&a[x[p]]==0)p++;
	while(q<=n&&b[y[q]]==0)q++;
	S.insert(mp(0,0));
	while(p<=n||q<=n){
		int pos=0,op=0;
		int xx=X,yy=Y;
		if(p>n)op=1;
		else if(q>n)op=0;
		else if(a[x[p]]-X>b[y[q]]-Y)op=1;
		else op=0;
		if(!op){
			Y+=a[x[p]]-X;
			X=a[x[p]];
		}
		else{
			X+=b[y[q]]-Y;
			Y=b[y[q]];
		}
		bool l=0,m=0,r=0;
		while(p<=n&&a[x[p]]==X){
			if(b[x[p]]==Y)m=1;
			if(b[x[p]]<Y)r=1;
			p++;
		}
		while(q<=n&&b[y[q]]==Y){
			if(a[y[q]]==X)m=1;
			if(a[y[q]]<X)l=1;
			++q;
		}
		if(!m&&(l||r)){
			ok[mp(X,Y)]=1;;
			if(l)X--;
			if(r)Y--;
			S.insert(mp(X+1,Y+1));
		}
	}
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		if(GG.count(mp(x,y))){puts("LOSE");continue;}
		if(ok.count(mp(x,y))){puts("WIN");continue;}
		pii w=*(--S.upper_bound(mp(x,y)));
		if((w.x-w.y)==(x-y))puts("LOSE");
		else puts("WIN");
	}
	return 0;
}