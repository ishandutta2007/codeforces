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
#define MN 2055
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m,ans[MN];
int id[MN],p[15],cnt;
bool vis[MN][MN];
namespace OI{
	int n,a[MN];
	void init(int n){
		for(int i=1;i<=n;++i)a[i]=i-1;
		random_shuffle(a+1,a+1+n);
		for(int i=1;i<=n;++i){
			cout<<a[i]<<" ";
		}
		cout<<endl<<endl;
	}
	int ask(int x,int y){return a[x]|a[y];}
}
int qry(int x,int y){
//	return OI::ask(x,y);
	cout<<"? "<<x<<" "<<y<<endl;
	int v;
	cin>>v;
	return v;
}
signed main(){
	srand(233);
	n=read();
//	OI::init(n);
	int o=1;
	for(int i=1;i<=n;++i)id[i]=i;
	random_shuffle(id+1,id+1+n);
	cnt=0;
	while(1){
		int x=rand()%n+1,y=rand()%n+1;
		if(x>y)swap(x,y);
		if(x==y)continue;
		if(vis[x][y])continue;
		vis[x][y]=1;
		int b=qry(id[x],id[y]);		
		for(int j=0;j<=11;++j)
			if(!((b>>j)&1)&&!p[j]) p[j]=x,cnt++; 
		if(cnt==12)break;
	}
//	cerr<<"done"<<endl;
	if(cnt!=12)cerr<<"GG "<<endl;
	int pre=p[0],now=1;
	for(int i=1;i<=n;++i){
		int b=pre==i?0:qry(id[pre],id[i]);
		if((b&((1<<now)-1))==0){
		//	cerr<<"ok: "<<id[i]<<endl;
			bool ok;
			do{
				int o=now;ok=0;
				if(p[o]==i){
					ok=1;now++;pre=i;
					continue;
				}
				int b=qry(id[p[o]],id[i]);
				if((b&(1<<o))==0){
					now++;pre=i;
					ok=1;
				}
			}while(ok&&(1<<now)<n);
		}
		if((1<<now)>=n)break;
	}
	for(int i=1;i<=n;++i){
		if(pre==i)continue;
		int b=qry(id[i],id[pre]);
		ans[id[i]]=b;
	}
	cout<<"! ";for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	return 0;
}