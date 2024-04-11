#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=105;
int n,k,m;
int cnt[N];
int lst[N];
int q[N];
int main(){
	scanf("%d%d%d",&n,&k,&m);
	int cc;scanf("%d",&cc);
	rep(i,1,cc){
		int x;scanf("%d",&x);
		cnt[x]++;
		lst[x]=i;
	}
	m-=cc;

	rep(i,1,n){
		int ct=0;
		if(k==n){
			if(cnt[i])printf("1 ");
			else if(m)printf("2 ");
			else printf("3 ");
			continue;
		}
		rep(j,1,n)if(j^i){
			if(m){
				if(cnt[j]>=cnt[i]+m)++ct;
			}
			else{
				if((cnt[j]>cnt[i])||((cnt[j]==cnt[i])&&(lst[j]<lst[i])))++ct;
			}
		}
		if(cnt[i]+m==0)ct=n+5;
		if(ct>=k)printf("%d ",3);
		else{
			q[0]=0;
			rep(j,1,n)if(j^i){
				int w=0;
				if(cnt[j]<cnt[i]){
					w+=cnt[i]-cnt[j]+1;
				}
				else if(cnt[j]==cnt[i]){
					if(lst[j]>lst[i])++w;
				}
				q[++q[0]]=w;
			}
			sort(q+1,q+1+q[0]);
			int cc=0;
			rep(j,1,k)cc+=q[j];
			if((cc<=m)||(cnt[i]==0))printf("2 ");
			else printf("1 ");
		}
	}
	return 0;
}