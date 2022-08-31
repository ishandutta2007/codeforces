#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int a[26];int n;int b[26];
bool f[25][25][1<<13];
int num1;
int sum[1<<13];
int np[1<<13];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	while(a[num1+1]==1)num1++;
	if(n==1&&num1==1){
		printf("YES");
		return 0;
	}
	if(num1==n){
		printf("NO");
		return 0;
	}
	rep(i,num1+1,n)b[i-num1]=a[i];int m=n-num1;
	if(num1<m){
		printf("NO");
		return 0;
	}
	rep(i,0,(1<<m)-1)rep(j,1,m)if((1<<(j-1))&i)sum[i]+=b[j];
	rep(i,1,(1<<m)-1)np[i]=np[i/2]+(i&1);
	f[0][num1][(1<<(n-num1))-1]=1;
	rep(i,0,n-num1-1)rep(j,0,num1)rep(me,0,(1<<(n-num1))-1)if(f[i][j][me]){
		int S=(1<<(m))-1-me;
		for(int p=S;p;p=(p-1)&S){
			int wei=sum[p];
			if(wei>b[i+1]-1)continue;
			if(b[i+1]-1-wei>j)continue;
			if(np[p]+b[i+1]-1-wei<2)continue;
			f[i+1][j-(b[i+1]-1-wei)][(p|me)-(1<<(i))]=1;
		}
		int p=0;
		int wei=sum[p];
		if(wei>b[i+1]-1)continue;
		if(b[i+1]-1-wei>j)continue;
		if(np[p]+b[i+1]-1-wei<2)continue;
		f[i+1][j-(b[i+1]-1-wei)][(p|me)-(1<<(i))]=1;
	}
	if(f[m][0][(1<<m)-1]||f[m][0][(1<<(m-1))-1]){
		printf("YES");
	}
	else printf("NO");
	return 0;
}