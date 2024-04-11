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
int n,k;
vector<int>ve[11];
long long p[11][41];
vector<long long>Vec;
int popc(long long x){
	int cn=0;
	while(x){
		++cn;x^=(x&-x);
	}
	return cn;
}
int main(){
	n=read(),k=read();
	if(n==1){
		printf("ACCEPTED\n");return 0;
	}
	for(int i=1;i<=k;++i){
		int j=read();
		for(int l=1;l<=j;++l){
			int x=read();ve[i].pb(x);
		}
		for(int l=1;l<=j;++l){
			p[i][l]=p[i][l-1]|(1ll<<ve[i][j-l]-1);
		}
	}
	long long su=0;Vec.pb(0);
	for(int i=1;i<=k;++i){
		vector<long long>nx;
		int sz=ve[i].size(),ne=popc(p[i][sz]&((1ll<<n)-1-su));
		for(long long j:Vec){
			int cn=0;
			for(int l:ve[i]){
				cn+=((j&(1ll<<l-1))!=0);
			}
			for(int l=0;l<=ne;++l){
				nx.pb(j&((1ll<<n)-1-p[i][sz])|p[i][l+cn]);
			}
		}
		Vec.clear();
		if(i==k) swap(Vec,nx);
		else {
			sort(nx.begin(),nx.end());
			long long ls=-1;
			for(long long j:nx){
				if(j!=ls) Vec.pb(j),ls=j;
			}
		}
		su|=p[i][sz];
	}
	if(su!=(1ll<<n)-1){
		printf("REJECTED\n");return 0;
	}
	for(long long j:Vec){
		// printf("%lld\n",j);
		bool f=0;
		for(int i=n;i>=1;--i){
			if(~j&(1ll<<i-1)){
				f=1;
			}
			else if(f){
				printf("REJECTED\n");return 0;
			}
		}
	}
	printf("ACCEPTED\n");
}