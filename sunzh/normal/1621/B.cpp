#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
signed main(){
	T=read();
	while(T--){
		n=read();
		int L=read(),R=read(),cl=read();int cr=cl;int one=cl;
		printf("%d\n",cl);
		bool fl=1;
		for(int i=2;i<=n;++i){
			int l=read(),r=read(),c=read();
			if(l<L&&r>R){
				L=l,R=r,cl=cr=one=c,fl=1;
			}
			else if(l<L){
				if(r==R) L=l,cl=one=c,cr=min(cr,c);
				else L=l,cl=c,fl=0,one=1e18;
			}
			else if(r>R){
				if(l==L) R=r,cr=one=c,cl=min(cl,c),fl=1;
				else R=r,cr=c,fl=0,one=1e18;
			}
			else if(l==L&&r==R) {
				one=min(one,c);cl=min(cl,c);cr=min(cr,c);
			}
			if(l==L) cl=min(cl,c);if(r==R) cr=min(cr,c);
			printf("%lld\n",min(cl+cr,one));
		}
	}
}