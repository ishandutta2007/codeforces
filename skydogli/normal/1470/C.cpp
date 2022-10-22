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
namespace OI{
	int val[100005],lst[100005];
	int n,p;
	void init(int N,int k,int P){
		n=N;p=P;
		for(int i=1;i<=n;++i)val[i]=k;
	}
	int query(int x){
		int v=val[x];
		for(int i=1;i<=n;++i){
			lst[i]=val[i];
			val[i]=0;
		}
		val[p%n+1]+=lst[p];
		for(int i=1;i<=n;++i){
			if(i==p)continue;
			val[(i-1+n-1)%n+1]+=lst[i]/2;
			val[i%n+1]+=lst[i]-lst[i]/2;
		}
		return v;
	}
}
#define MN 4005
#define mn 1005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m,k;
int val[mn][MN];
int py;
int ok[100005];
int qry(int x){
//	return OI::query(x);
	cout<<"? "<<x<<endl;
	int v;cin>>v;
	return v;
}
signed main(){
	n=read();k=read();
//	OI::init(n,k,233);
	int x=1,d=1,v;
	do{
		x=(x+d-1)%n+1;
		d++;
		v=qry(x);
	}while(v==k);
	while(v>k){x=(x==1)?n:x-1;v=qry(x);}
	while(v<k){x=(x==n)?1:x+1;v=qry(x);}
	cout<<"! "<<x<<endl;
	return 0;
}