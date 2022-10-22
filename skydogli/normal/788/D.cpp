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
const int inf=100000001;
int ask(int x,int y){
	cout<<0<<" "<<x<<" "<<y<<endl;
	int s;cin>>s;
	return s;
}
vc<int>ans;
int GG;
void work(int l,int r){
	if(l+1>=r)return;
	int mid=(l+r)>>1;
//	cerr<<"fk: "<<l<<" "<<r<<endl;
	int t=ask(mid,mid);
	if(t==0){ans.pb(mid);work(l,mid);work(mid,r);}
	else if(mid+t<r&&ask(mid+t,mid+t)==0){ans.pb(mid+t);work(l,mid+t);work(mid+t,r);}
	else if(mid-t>l&&ask(mid-t,mid-t)==0){ans.pb(mid-t);work(l,mid-t);work(mid-t,r);}
	else GG=mid;
}
signed main(){
	work(-inf,inf);
	vc<int>X,Y;
	for(auto i:ans){
		int t=ask(GG,i);
		if(!t){
			X.pb(i);
			if(ask(i,GG)==0)Y.pb(i);
		}
		else Y.pb(i);
	}
//	cerr<<"done!"<<endl;
	swap(X,Y);
	cout<<1<<" "<<X.size()<<" "<<Y.size()<<endl;
	for(auto i:X)cout<<i<<" ";
	cout<<endl;
	for(auto i:Y)cout<<i<<" ";
	return 0;
}