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
#define MN 1000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,k,val[MN],loc[MN],fk[MN];
int to[MN<<2][2],siz[MN<<2],cnt=1;
int st[MN<<2],top;
int p[MN<<2],in[MN<<2];
int newnode(){
	int x;
	if(top){in[st[top]]=0;x=st[top--];}
	else x=++cnt;
	if(!x||x==1){cout<<"FKFKF"<<endl;exit(0);}
	to[x][0]=to[x][1]=0;siz[x]=0;
	return x;
}
int node(int &x){
	if(!x)x=newnode();
	return x;
}
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;++i)loc[i]=fk[i]=1;
	for(int i=2;i<=n;++i){
		int fa=read();val[i]=read()^val[fa];
	}
	sort(val+1,val+1+n);
	int ans=0;
	for(int i=61;i>=0;--i){
		int N=0;
		for(int j=1;j<=n;++j){
			if(!in[loc[j]]&&loc[j]>1)p[++N]=loc[j],in[loc[j]]=1;
			loc[j]=node(to[loc[j]][(val[j]>>i)&1]);
			siz[loc[j]]++;
		}
		int tot=0;
		for(int j=1;j<=n;++j){
			tot+=siz[to[fk[j]][(val[j]>>i)&1]];	
		}
		if(tot<k){
			k-=tot,ans|=(1ll<<i);
			for(int j=1;j<=n;++j){
				fk[j]=to[fk[j]][!((val[j]>>i)&1)];
			}
		}
		else {
			if(!i){
				if(tot<k){cout<<"tot<k"<<endl;exit(0);}
			}
			for(int j=1;j<=n;++j){
				fk[j]=to[fk[j]][(val[j]>>i)&1];
			}
		}
		for(int j=1;j<=N;++j)st[++top]=p[j];
	}
	printf("%lld\n",ans);
	return 0;
}