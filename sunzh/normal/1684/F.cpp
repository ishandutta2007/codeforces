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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
int a[200010],b[200010];
int lst[200010],nxt[200010],pr[200010];
vector<int>que[200010];
int rgt[200010],lft[200010];
int pmn[200010],smn[200010],pmx[200010];
vector<int>vec[200010];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=read(),b[i]=a[i],vector<int>().swap(vec[i]),lst[i]=0;
		sort(b+1,b+n+1);
		for(int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+n+1,a[i])-b,vec[a[i]].pb(i);
		for(int i=1;i<=n;++i){
			if(lst[a[i]]){
				pr[i]=lst[a[i]];
				nxt[lst[a[i]]]=i;
			}
			lst[a[i]]=i;nxt[i]=n+1;
		}
		for(int i=1;i<=n;++i) lft[i]=i,rgt[i]=i;
		for(int i=1;i<=m;++i){
			int l=read(),r=read();
			rgt[l]=max(rgt[l],r);
			lft[r]=min(lft[r],l);
		}
		pmn[0]=n+1;
		for(int i=1;i<=n;++i) rgt[i]=max(rgt[i-1],rgt[i]);
		for(int i=n-1;i>=1;--i) lft[i]=min(lft[i+1],lft[i]);
		for(int i=1;i<=n;++i) if(!nxt[i]) nxt[i]=n+1;
		for(int i=1;i<=n;++i){
			if(pr[i]>=lft[i]){
				smn[i]=*lower_bound(vec[a[i]].begin(),vec[a[i]].end(),lft[i]);
			}
			else smn[i]=n+1;
			if(nxt[i]<=rgt[i]){
				pmn[i]=nxt[i];
				auto it=upper_bound(vec[a[i]].begin(),vec[a[i]].end(),rgt[i]);
				if(it!=vec[a[i]].begin()){
					--it;
					pmx[i]=*it;
				}
			}
			else pmn[i]=n+1,pmx[i]=0;
		}
		for(int i=2;i<=n;++i) pmn[i]=min(pmn[i-1],pmn[i]),pmx[i]=max(pmx[i-1],pmx[i]);
		for(int i=n-1;i;--i) smn[i]=min(smn[i],smn[i+1]);
		int ans=n;
		for(int i=n;i>=1;--i){
			int l=1,r=min(i+1,smn[i+1]);
			int res=-n;
			while(l<=r){
				int mid=l+r>>1;
				if(pmn[mid-1]>=mid&&pmx[mid-1]<=i){
					res=mid;l=mid+1;
				}
				else r=mid-1;
			}
			ans=min(ans,i-res+1);
			if(nxt[i]<=rgt[i]) break ;
		}
		printf("%d\n",min(n,max(0,ans)));
	}
}