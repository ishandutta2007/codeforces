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
#define MN 1000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,edg[MN];
char ch[MN];
signed main(){
	cin>>T;
	while(T--){
		scanf("%s",ch+1);
		n=strlen(ch+1);
		int now=n;
		for(int i=0;i<=n*2;++i)edg[i]=0;
		for(int i=1;i<=n;++i){
			if(ch[i]=='1'){edg[now]++;now++;}
			else{edg[now-1]++;now--;}
		}
		now=n;
		for(int i=1;i<=n;++i){
			if((!edg[now]&&edg[now-1])||(edg[now-1]>1)){
				putchar('0');
				now--;
				edg[now]--;
			}
			else {
				putchar('1');
				edg[now]--;
				now++;
			}
		}
		puts("");
	}
	return 0;
}