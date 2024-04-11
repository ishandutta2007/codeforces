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
#define MN 800005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n;
pii  a[MN];
priority_queue<int>A;
priority_queue<int,vector<int>,greater<int> >B;
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		a[i]=mp(x+y,x-y);
	}
	sort(a+1,a+1+n);
	A.push(0);B.push(0);
	int ans=0;
	for(int i=1;i<=n;++i){
		int x=a[i].x,y=a[i].y;
		ans+=max(0ll,max(y-x-B.top(),A.top()-x-y));
		if(y-x<=B.top()){
			A.push(x+y);A.push(x+y);B.push(A.top()-x*2);A.pop();
		}
		else{
			B.push(y-x);B.push(y-x);A.push(B.top()+x*2);B.pop();
		}
	}
	cout<<ans/2<<endl;
	return 0;
}