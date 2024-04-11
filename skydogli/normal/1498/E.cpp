#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
int f[205][100005],n,m;
#define eps 1e-10
#define piii pair<int,pair<int,int> >
#define mp make_pair
#define x first
#define y second
int a[505],N;
piii mt[250005];
signed main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		if(i!=j)
			mt[++N]=mp(abs(a[i]-a[j]),mp(i,j));
	sort(mt+1,mt+1+N);
	reverse(mt+1,mt+1+N);
	for(int i=1;i<=N;++i){
		int x=mt[i].y.x,y=mt[i].y.y;
		if(a[x]<a[y])swap(x,y);
		cout<<"? "<<x<<" "<<y<<endl;
		string s;cin>>s;
		if(s=="Yes"){
			cout<<"! "<<x<<" "<<y<<endl;
			return 0;
		}
	}
	cout<<"! "<<0<<" "<<0<<endl;
	return 0;
}