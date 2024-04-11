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
int n,k;
int a[500010];
char str[500010];
signed main(){
	int T=read();
	while(T--){
		n=read(),k=read();
		scanf("%s",str+1);
		for(int i=1;i<=n;++i){
			a[i]=str[i]-'a';
		}
		int lst=0;
		for(int i=1;i<=n;++i){
			if(a[i]<=lst) printf("a");
			else{
				if(k-(a[i]-lst)>=0){
					k-=(a[i]-lst);
					lst=a[i];
					printf("a");
				}
				else{
					int r=a[i],l=a[i]-k;
					// printf("%d %d\n",l,r);
					for(int j=i;j<=n;++j){
						if(a[j]<=lst) printf("a");
						else if(a[j]>=l&&a[j]<=r) printf("%c",l+'a');
						else printf("%c",a[j]+'a');
					}
					break ;
				}
			}
		}
		printf("\n");
	}
}