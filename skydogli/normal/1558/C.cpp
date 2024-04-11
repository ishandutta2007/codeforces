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
vc ans;
void fk(int p){
	ans.pb(p);
	reverse(a+1,a+1+p);
}
int Find(int v){
	for(int i=1;i<=n;++i)
		if(a[i]==v)return i;
}
signed main(){
	T=read();
	while(T--){
		ans.clear();
		n=read();
		bool GG=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]%2!=i%2)GG=1;
		}
		if(GG){puts("-1");continue;}
		for(int i=n;i>1;i-=2){
			int x=Find(i);
			fk(x);
			int y=Find(i-1);
			fk(y-1);
			fk(y+1);
			fk(3);
			fk(i);
		}
		cout<<ans.size()<<" "<<'\n';
		for(auto i:ans)cout<<i<<" ";
		cout<<'\n';
	}
	return 0;
}