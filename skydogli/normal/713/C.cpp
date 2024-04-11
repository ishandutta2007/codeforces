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
#define MN 3005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int a[MN],n;
priority_queue<int>Q;
signed main(){
	n=read();
	int ans=0;
	for(int i=1;i<=n;++i){
		int x=read()-i;Q.push(x);
		if(x<Q.top()){
			ans+=Q.top()-x;
			Q.pop();
			Q.push(x);
		}
	}
	cout<<ans<<endl;
	return 0;
}