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
inline long long read(){
	long long x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
long long query(int l,int r){
	printf("? %d %d\n",l,r);fflush(stdout);
	return read();
}
int main(){
	T=read();
	while(T--){
		n=read();
		long long all=query(1,n);
		int l=1,r=n,res=n;
		auto check=[&](int x){
			return query(x,n)!=all;
		};
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)){
				r=mid-1,res=mid;
			}
			else l=mid+1;
		}
		int i=res-1,j,k;
		j=i+all-query(res,n)+1;
		k=j+query(j,n)-query(j+1,n);
		printf("! %d %d %d\n",i,j,k);fflush(stdout);
	}
}