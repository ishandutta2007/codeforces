#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,q;
int a[100010];
int cnt[100010];
int tot4,tot2;
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		++cnt[a[i]];
		if(cnt[a[i]]%2==0) ++tot2;
		if(cnt[a[i]]%4==0) ++tot4;
	}
	q=read();
	while(q--){
		char c=getchar();
		while(c!='+'&&c!='-') c=getchar();
		if(c=='+'){
			int x=read();
			++cnt[x];
			if(cnt[x]%2==0) ++tot2;
			if(cnt[x]%4==0) ++tot4;
		}
		else{
			int x=read();
			if(cnt[x]%4==0) --tot4;
			if(cnt[x]%2==0) --tot2;
			--cnt[x];
		}
		if(tot4&&tot2>=4) printf("YES\n");
		else printf("NO\n");
	}
}