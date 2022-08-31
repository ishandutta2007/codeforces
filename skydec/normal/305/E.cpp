#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int sg[5005];
int n;char a[5005];int tmp[5005];
inline int getsg(int l,int r){
	int len=0;int ans=0;
	rep(i,l+1,r-1){
		if(a[i+1]==a[i-1])len++;
		else{
			ans^=sg[len];
			len=0;
		}
	}
	ans^=sg[len];
	return ans;
}
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	rep(i,1,n){
		rep(j,1,i)tmp[sg[max(0,j-2)]^sg[max(i-j-1,0)]]=i;
		while(tmp[sg[i]]==i)sg[i]++;
	}
	rep(i,2,n-1)if(a[i+1]==a[i-1]&&(getsg(1,i-1)==getsg(i+1,n))){
		printf("First\n%d\n",i);
		return 0;
	}
	printf("Second");
	return 0;
}