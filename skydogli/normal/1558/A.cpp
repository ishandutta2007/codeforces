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
int T,a,b;
signed main(){
	T=read();
	while(T--){
		a=read(),b=read();
		vc w(0);
		if(a>b)swap(a,b);
		int lim=(b-a+1)/2+a*2;
		if((b-a)%2==0)
			for(int i=(b-a)/2;i<=lim;i+=2)w.pb(i);
		else
			for(int i=(b-a)/2;i<=lim;++i)w.pb(i);
		cout<<w.size()<<'\n';
		for(auto i:w)cout<<i<<" ";
		cout<<'\n';
	}
	return 0;
}