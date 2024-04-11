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
int n;
char s[100010],t[100010];
int tre[100010];
vector<int>vec[26];
void upd(int x,int k){
	while(x<=n){
		tre[x]+=k;x+=x&-x;
	}
}
int qry(int x){
	int res=0;
	while(x){
		res+=tre[x];x-=x&-x;
	}
	return res;
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);scanf("%s",t+1);
		for(int i=1;i<=n;++i) tre[i]=0;
		for(int i=0;i<26;++i) vector<int>().swap(vec[i]);
		for(int i=n;i>=1;--i){
			vec[s[i]-'a'].pb(i);
		}
		long long ans=0x3f3f3f3f3f3f3f3f;
		long long pr=0;
		for(int i=1;i<=n;++i){
			int p=t[i]-'a';
			long long mn=0x3f3f3f3f3f3f3f3f;
			for(int j=0;j<p;++j){
				if(vec[j].size()){
					int v=vec[j].back();
					mn=min(mn,(long long)v+qry(v)-i);
				}
			}
			ans=min(ans,mn+pr);
			if(vec[p].size()){
				int v=vec[p].back();vec[p].pop_back();
				pr+=v+qry(v)-i;v+=qry(v);
				int l=1,r=n,res=0,res2=0;
				while(l<=r){
					int mid=l+r>>1;
					if(mid+qry(mid)<=i){
						res=mid,l=mid+1;
					}
					else r=mid-1;
				}
				l=1,r=n;
				while(l<=r){
					int mid=l+r>>1;
					if(mid+qry(mid)<=v){
						res2=mid,l=mid+1;
					}
					else r=mid-1;
				}
				upd(res,1);upd(res2+1,-1);
			}
			else break ;
		}
		if(ans>1e14) printf("-1\n");else printf("%lld\n",ans);
	}
}