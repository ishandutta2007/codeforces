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
#define vc vector<int>
int T,n,m;
int a[MN],ti[MN];
char ch[MN],CH[MN];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		scanf("%s",ch+1);
		for(int i=1;i<=n;++i)ti[i]=2e9,CH[i]=ch[i];;
		for(int i=1;i<=n;++i){
			if(ch[i]=='1'){
				int t=0;
				for(int j=i-1;j;--j){
					t++;
					if(ch[j]=='1')break;
					if(ti[j]>i-j)ti[j]=i-j,CH[j]='1';
					else if(ti[j]==i-j)CH[j]='0';
					else break;
					if(t==m)break;
				}
				t=0;
				for(int j=i+1;j<=n;++j){
					t++;
					if(ch[j]=='1')break;
					if(ti[j]>j-i)ti[j]=j-i,CH[j]='1';
					else if(ti[j]==j-i)CH[j]='0';
					else break;
					if(t==m)break;
				}
			}
		}
		for(int i=1;i<=n;++i)putchar(CH[i]);
		puts("");
	}
	return 0;
}