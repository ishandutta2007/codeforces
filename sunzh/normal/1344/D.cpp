#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,k;
int a[100010];
int ans[100010];
const int LLMAX=((1ll<<63)-1)>>1;
int check(int x){
	int sum=0;
	for(int i=1;i<=n;++i){
		int l=0,r=a[i],res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]-3*mid*mid-3*mid-1>=x){
				l=mid+1,res=mid;
			}
			else r=mid-1;
		}
		sum+=res;
	}
	return sum;
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int l=-LLMAX,r=LLMAX,res=-1;
	while(l<=r){
		int mid=l+r>>1;
		int x=check(mid);
		if(x<=k){
			r=mid-1,res=mid;
		}
		else l=mid+1;
	} 
	int lft=k-check(res);
	for(int i=1;i<=n;++i){
		int l=0,r=a[i],tmp=0;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]-3*mid*mid-3*mid-1>=res){
				l=mid+1,tmp=mid;
			}
			else r=mid-1;
		}
		if(lft&&tmp+1<=a[i]&&a[i]-3*(tmp+1)-3*(tmp+1)*(tmp+1)-1==res-1){
			--lft,ans[i]=tmp+1;
		}
		else ans[i]=tmp;
		print(ans[i]);putchar(' ');
	}
}