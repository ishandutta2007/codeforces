#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

int n,sum,ans[6005],p[6000005],tot;
bool vis[18800005];

void Ethan_Ben(int x){
	tot++;
	for(int i=n;i>=1;i--)
		if(x>=i&&!ans[i]) ans[i]=tot,x-=i;
}

int main(){
	scanf("%d",&n);
	sum=(n+1)*n/2;
	vis[1]=1;
	for(int i=2;i<=sum;i++){
		if(!vis[i])p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=sum;j++){
			vis[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
	tot=0;
	if(!vis[sum]) Ethan_Ben(sum);
	else{
		if(!vis[sum-2]) Ethan_Ben(2),Ethan_Ben(sum-2),sum=0;
		if(sum&1) Ethan_Ben(3),sum-=3;
		for(int i=2;i<sum;i++)
			if(!vis[i]&&!vis[sum-i]) {Ethan_Ben(i),Ethan_Ben(sum-i);break;}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}