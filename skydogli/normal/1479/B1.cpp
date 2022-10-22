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
int a[MN];
signed main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	int lst=0;
	vector<int>v;int ans=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(a[j+1]==a[i])j++;
		if(i==j){v.push_back(a[i]);continue;}
		if(a[i]!=lst){ans+=v.size()+2;lst=a[i];v.clear();continue;}
		if(v.size()){
			ans+=v.size()+1;
			if(v.size()==1){
				v.clear();
				continue;
			}
		}
		else continue;
		bool ok=0,gg=0;
		int I=i;
		for(int i=0;i+1<v.size();++i)
			if(v[i]!=a[I]&&v[i+1]!=a[I]){
				ok=1;
			}
		if(ok)ans++;
		v.clear();
	}
	ans+=v.size();
	printf("%lld\n",ans);
	return 0;
}