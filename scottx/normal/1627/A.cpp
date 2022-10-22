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

#define N 55

char a[N][N];
int n,m,r,c;

void Solve(){
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	} 
	if(a[r][c]=='B'){
		puts("0");
		return;
	}
	bool ok1=0,ok2=0;
	for(int i=1;i<=m;i++)ok1|=a[r][i]=='B';
	for(int i=1;i<=n;i++)ok2|=a[i][c]=='B';
	if(ok1||ok2){
		puts("1");
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ok1|=a[i][j]=='B';
		}
	}
	if(ok1){
		puts("2");
		return;
	}
	puts("-1"); 
}

int main(){
	int T=read();
	while(T--){
		Solve();
	}
	return 0;
}