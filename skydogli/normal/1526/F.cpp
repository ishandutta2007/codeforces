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
#define vc vector
int T,n;
pii val[MN];
int ans[MN];
//int p[MN];
int qry(int a,int b,int c){
//	assert(a!=b&&b!=c&&a!=c);
//	if(p[a]>p[b])swap(a,b);
//	if(p[b]>p[c])swap(b,c);
//	if(p[a]>p[b])swap(a,b);
//	return max(p[b]-p[a],p[c]-p[b]);
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	int v;cin>>v;
	return v;
}
#define y1 hhakioi
signed main(){
	ios::sync_with_stdio(0);
	T=read();
	while(T--){
		n=read();
//		for(int i=1;i<=n;++i)
//			p[i]=i;
//		random_shuffle(p+1,p+1+n);
//		if(p[1]>p[2])for(int i=1;i<=n;++i)p[i]=n-p[i]+1;
//		for(int i=1;i<=n;++i){
//			cerr<<p[i]<<" ";
//		}
//		cerr<<endl;
		int A=0,B=0;
		while(1){
			int a=rand()%n+1,b=rand()%n+1,c=rand()%n+1;	
			while(a==b||a==c||b==c)a=rand()%n+1,b=rand()%n+1,c=rand()%n+1;	
			if(qry(a,b,c)<=(n-4)/6){A=a,B=b;break;}
		}
		int mx=0,pos=0;
		for(int i=1;i<=n;++i){
			if(i!=A&&i!=B)val[i]=mp(qry(A,B,i),i);
			else val[i]=mp(0,0);
		}	
		sort(val+1,val+1+n);
		reverse(val+1,val+1+n);
		int aa=val[1].y,bb;
		pii y1,y2;
		if(val[2].x==val[1].x)y1=val[3],y2=val[4];
		else y1=val[2],y2=val[3];
		if(y1.x==y2.x){
			if(qry(aa,A,y1.y)<qry(aa,A,y2.y))bb=y1.y;
			else bb=y2.y;
		}
		else bb=y1.y;
//		cerr<<"find: "<<aa<<" "<<bb<<endl;
		ans[aa]=1;ans[bb]=2;
		for(int i=1;i<=n;++i){
			if(i==aa||i==bb)continue;	
			ans[i]=2+qry(aa,bb,i);
		}
		if(ans[1]>ans[2])
			for(int i=1;i<=n;++i)ans[i]=n-ans[i]+1;
		cout<<"! ";
		for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
		cout<<endl;
		int sb;cin>>sb;
	}
	return 0;
}

//tm