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
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
char str[100010];
int n,a,b,c,m;
int tl[100010];
signed main(){
	T=read();
	for(int o=1;o<=T;++o){
		n=read(),a=read(),b=read(),c=read();
		scanf("%s",str+1);
		int c0=0,c1=0,l0=0,l1=0,cn=0;
		for(int i=1;i<=n;++i){
			if(str[i]=='0'){
				tl[++cn]=1;
				int p=i;
				while(str[i+1]=='0') ++i,++tl[cn];
				if(p==1||i==n) --cn;
			}
		}
		for(int i=1;i<=n;++i){
			if(str[i]=='0'){
				++l0;if(str[i-1]=='0') ++c0;
			}
			else{
				++l1;if(str[i-1]=='1') ++c1;
			}
		}
		int ans=0;
		if(c0>=c1){
			ans=min(c0,c1+1)*a+c1*b;
			sort(tl+1,tl+cn+1);
			int sum=0;
			for(int i=1;i<=cn;++i){
				if(sum+tl[i]-1<=c1){
					sum+=tl[i]-1;if(b-c>0)ans+=b-c;
				}
				else break ;
			}
		}
		else{
			// if(n>=25000){
			// 	printf("c0:%d,c1:%d,l0:%d,l1:%d\n",c0,c1,l0,l1);
			// }
			ans=min(c0,c1)*(a+b);
			if(b-c>0) ans+=(cn+min(c1-c0-1,(int)(str[1]=='0')+(str[n]=='0')))*(b-c);
			ans+=b;
		}
  		printf("%lld\n",ans);
		// else if(o==1037) printf("%d %d %d %d\n%s\n",n,a,b,c,str+1);
	}
}