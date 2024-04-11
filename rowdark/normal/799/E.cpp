#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int opt[200100];
int n,m,k,a,b,x;
pair<int,int> c[200100];
vector<int> F[4];
long long ans=~0ULL>>1;
pair<int,long long> lt[262170];
void insert(int x,int a,int b){
	while(x<262144){
		lt[x].first+=a;
		lt[x].second+=b;
		x+=x&-x;
	}
}
inline void erase(int x){
	insert(x,-1,-c[x].first);
}
inline void insert(int x){
	insert(x,1,c[x].first);
}
inline long long query(int x){
	long long ret=0;
	for(int i=0,j=131072;j;j>>=1){
		if(x>=lt[i+j].first){
			i+=j;
			x-=lt[i].first;
			ret+=lt[i].second;
		}
	}
	return ret;
}
inline void solve(){
	int lim=min(k,(int)F[3].size());
	long long tmp=0;
	int sel=0;
	for(int i=0;i<lim;++i) erase(F[3][i]),tmp+=c[F[3][i]].first,++sel;
	for(int i=0;i<k-lim;++i){
		erase(F[1][i]),tmp+=c[F[1][i]].first,++sel;
		erase(F[2][i]),tmp+=c[F[2][i]].first,++sel;
	}
	for(int i=lim;i>=0;--i){
		if(i!=lim){
			insert(F[3][i]),tmp-=c[F[3][i]].first,--sel;
			if((int)F[1].size()>=k-i&&(int)F[2].size()>=k-i){
				erase(F[1][k-1-i]),tmp+=c[F[1][k-1-i]].first,++sel;
				erase(F[2][k-1-i]),tmp+=c[F[2][k-1-i]].first,++sel;
			}
			else break;
		}
		if(sel>m) break;
		ans=min(ans,tmp+query(m-sel));
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k>m){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;++i) scanf("%d",&c[i].first),c[i].second=i;
	scanf("%d",&a);
	for(int i=0;i<a;++i){
		scanf("%d",&x);
		opt[x]|=1;
	}
	scanf("%d",&b);
	for(int i=0;i<b;++i){
		scanf("%d",&x);
		opt[x]|=2;
	}
	if(a<k||b<k){
		printf("-1\n");
		return 0;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i){
		F[opt[c[i].second]].push_back(i);
		insert(i,1,c[i].first);
	}
	solve();
	cout<<(ans==(~0ULL>>1)?-1:ans)<<endl;
	return 0;
}