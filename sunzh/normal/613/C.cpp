#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[30];
int odd,num;
char str[10000010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) odd+=(a[i]&1),num=((a[i]&1)?i:num);
	if(odd>1){
		printf("0\n");
		for(int i=1;i<=n;++i){
			for(int j=1;j<=a[i];++j) putchar('a'+i-1);
		}
	}
	else{
		int gcd=0;
		for(int i=1;i<=n;++i){
			int v=(num==i?a[i]:a[i]/2);
			if(!gcd) gcd=v;
			else gcd=__gcd(gcd,v);
		}
		printf("%d\n",(odd?gcd:2*gcd));
		if(!gcd){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=a[i];++j) putchar('a'+i-1);
			}
			return 0;
		}
		int totlen=0;
		for(int i=1;i<=n;++i){
			totlen+=(a[i]/gcd);
		}
		int pre=1,suf=totlen;
		for(int i=1;i<=n;++i){
			int t=a[i]/2/gcd;
			while(t--){
				str[pre++]='a'+i-1;
				str[suf--]='a'+i-1;
			}
		}
		if(odd) str[pre]='a'+num-1;
		for(int i=1;i<=gcd;++i) printf("%s",str+1);
	}
}