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
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[MN];
char ch[MN];
bool vis[2005];
int V=10;
void init(){	
	for(int i=1;i<=n;++i){
		a[i]=rand()%V+1;
		a[i]=read();
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int qry(int x){
/*	int u=0,s=0;
	for(int i=1;i<=n;++i){
		if(a[i]>x)return 0;
		if(a[i]+u+1>x||!s)s++,u=a[i];
		else u+=a[i]+1;
	}
	return s;*/
	cout<<"? "<<x<<endl;
	int w;cin>>w;
	return w;
}
signed main(){
	srand(time(0));
	n=read();
//	init();
	int l=0,r=n*2001;
	while(l+1<r){
		int mid=(l+r)>>1;
		int a=qry(mid);
		if(a==1)r=mid;
		else l=mid;
	}
	cerr<<"r: "<<r<<endl;
	int ans=r,lst=ans;
	for(int i=2;i<=n;++i){
		int mx=0,t=0;
		for(int j=2;j<=n;++j){
			if(!vis[j]&&mx<ans-(ans-1)/j*j)t=j,mx=ans-(ans-1)/j*j;
		}
		vis[t]=1;int j=t;
//		cerr<<"q: "<<j<<endl;
		if(lst-(ans-mx)>j)continue;
		bool flag=0;
		do{
			flag=0;
			int a=qry((ans-1)/j);
			if(a!=0&&a<=j)ans=(ans-1)/j*a,flag=1;
		}while(0);
	}
	cout<<"! "<<ans<<endl;
	return 0;
}