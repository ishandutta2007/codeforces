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
int T,n,m;
int a[MN],F[MN];
int x,y,L[MN],R[MN];
int pre[MN][2],suf[MN][2];
char ch[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
int solve(int O){//0-1
	if(O){
		reverse(ch+1,ch+1+n);
		swap(x,y);
	}
	for(int i=1;i<=n;++i){
		pre[i][0]=pre[i-1][0];
		pre[i][1]=pre[i-1][1];
		if(ch[i]!='?')pre[i][ch[i]]++;
	}
	for(int i=n;i;--i){
		suf[i][0]=suf[i+1][0];
		suf[i][1]=suf[i+1][1];
		if(ch[i]!='?')suf[i][ch[i]]++;
	}
	for(int i=1;i<=n;++i){
		L[i]=L[i-1];
		if(ch[i]==1)L[i]+=(i-pre[i][1])*x;
		else L[i]+=pre[i][1]*y;
//		cerr<<"L "<<i<<" "<<(int)ch[i]<<" "<<pre[i][1]<<": "<<L[i]<<endl;
	}
	for(int i=n;i;--i){
		R[i]=R[i+1];
		if(ch[i]==0)R[i]+=(n-i-suf[i+1][0])*x;
		else R[i]+=suf[i][0]*y;
//		cerr<<"R "<<i<<": "<<R[i]<<endl;
	}
	int res=1e18;
	for(int i=0;i<=n;++i){
		res=min(res,L[i]+R[i+1]+(i-pre[i][1])*(n-i-suf[i+1][0])*x+pre[i][1]*suf[i+1][0]*y);
	}
	return res;
}
signed main(){
	scanf("%s",ch+1);
	cin>>x>>y;
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)if(ch[i]!='?')ch[i]-='0';
	int res=solve(0);
	res=min(res,solve(1));
	printf("%lld\n",res);
	return 0;
}