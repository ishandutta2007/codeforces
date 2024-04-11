#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
PII d[2500010];
int n;
int a[200010];
struct node{
	int x,id;
	bool operator <(const node &a)const{
		return x<a.x;
	}
}b[200010];
int tmp[200010],cnt[200010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i].x=a[i],b[i].id=i;
	sort(b+1,b+n+1);
	int m=0;
	for(int i=1;i<=n;++i){
		if(b[i].x!=tmp[m]) tmp[++m]=b[i].x,cnt[m]=1;
		else ++cnt[m];
		if(cnt[m]>=4){
			printf("YES\n");
			printf("%d %d %d %d\n",b[i].id,b[i-1].id,b[i-2].id,b[i-3].id);
			exit(0);
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=i+1;j<=m;++j){
			if(cnt[i]>1&&cnt[j]>1){
				printf("YES\n");
				int A=lower_bound(b+1,b+n+1,node{tmp[i],0})-b;
				int B=lower_bound(b+1,b+n+1,node{tmp[j],0})-b;
				printf("%d %d %d %d\n",b[A].id,b[B].id,b[A+1].id,b[B+1].id);
				exit(0);
			}
			int det=tmp[j]-tmp[i];
			int A=lower_bound(b+1,b+n+1,node{tmp[i],0})-b;
			int B=lower_bound(b+1,b+n+1,node{tmp[j],0})-b;
			if(d[det].fi){
				if(d[det].se==A&&cnt[i]==1){
					continue ;
				}
				if(d[det].se==A) ++A;
				printf("YES\n%d %d %d %d\n",b[d[det].fi].id,b[B].id,b[A].id,b[d[det].se].id);
				exit(0);
			}
			else d[det]=mp(A,B);
		}
	}
	printf("NO\n");
}