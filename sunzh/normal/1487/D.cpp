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
int T;
int n;
int main(){
	T=read();
	while(T--){
		n=read();
		int res=0;
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			int t=(mid<<1|1);
			if(t>=n) r=mid-1;
			else{
				long long t2=1+(1ll*t*t>>1ll);
				if(t2>n) r=mid-1;
				else res=mid,l=mid+1;
			}
		}
		printf("%d\n",res);
	}
}