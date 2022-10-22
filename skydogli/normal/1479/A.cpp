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
#define pb push_back
#define y second
int T,n,m;
int a[MN];
char ch[MN];
int Q(int x){
	if(x<1||x>n)return 1e9;
	cout<<"? "<<x<<endl;
	int v;cin>>v;
	return v;
}
void out(int x){cout<<"! "<<x<<endl;}
void solve(int l,int r){
	if(l==r){out(l);exit(0);}
	int mid=(l+r)>>1;
	int u=Q(mid-1),v=Q(mid),o=Q(mid+1);	
	if(u>v&&v<o){
		out(mid);
		exit(0);
	}
	else if(u<o){
		solve(l,mid-1);
	}
	else solve(mid+1,r);
}
signed main(){
	n=read();
	a[0]=a[n+1]=1e9;
	solve(1,n);
	return 0;
}