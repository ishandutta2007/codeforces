#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define mn 2005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,cnt;
struct P{
	int x,y,id,to;
	int len(){return x*x+y*y;}
}a[mn],b[mn];
int operator ^(P a,P b){return a.x*b.y-a.y*b.x;}
bool cmp(P a,P b){
	if((a^b)==0)return a.len()<b.len();
	return (a^b)>0;
}
int F[mn];
int Find(int a){if(F[a]==a)return a;return F[a]=Find(F[a]);}
void Merge(int a,int b){
	F[Find(a)]=Find(b);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i)F[i]=i;
	for(int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read(),a[i].id=i,a[i].to=read();
		Merge(a[i].id,a[i].to);
	}
	int pos=0;
	for(int i=1;i<=n;++i)if(a[i].id!=a[i].to&&(!pos||a[pos].x>a[i].x))pos=i;
	if(!pos){puts("0");return 0;}
	swap(a[1],a[pos]);
	for(int i=1;i<=n;++i)if(a[i].id!=a[i].to)b[++cnt]=a[i];
	for(int i=cnt;i;--i)b[i].x-=b[1].x,b[i].y-=b[1].y;
	sort(b+2,b+1+cnt,cmp);
	vector<pii >ans;
	for(int i=3;i<=cnt;++i)
		if(Find(b[i].id)!=Find(b[i-1].id)){
			Merge(b[i].id,b[i-1].id);	
			ans.pb(mp(b[i].id,b[i-1].id));
			swap(b[i].to,b[i-1].to);
		}
	for(int i=1;i<cnt;++i){
		assert(b[1].id!=b[1].to);
		ans.pb(mp(b[1].id,b[1].to));
		for(int j=1;j<=cnt;++j)
			if(b[j].id==b[1].to){
				swap(b[j].to,b[1].to);
				break;
			}
	}
	assert(b[1].id==b[1].to);
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.x<<" "<<i.y<<'\n';
	return 0;
}