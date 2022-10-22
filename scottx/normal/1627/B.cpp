// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<class T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

int qwq[200005];
int n,m,len;

void Solve(){
	n=read(),m=read();
	len=0;
	rep(i,1,n){
		rep(j,1,m){
			qwq[++len]=max(i-1,n-i)+max(j-1,m-j);
		}
	}
	sort(qwq+1,qwq+len+1);
	rep(i,1,len){
		printf("%d ",qwq[i]);
	}
	puts("");
}

int main(){
	int T=read();
	while(T--){
		Solve();
	}
	return 0;
}