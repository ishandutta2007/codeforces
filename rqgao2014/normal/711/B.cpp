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
#define lb lower_bound
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

const int N=505;
int n;
int a[N][N],x,y;
ll b[N][N];

inline void wrong(){
	puts("-1");exit(0);
}
inline ll get(){
	for(int i=1;i<=n;i++){
		if(x==i) continue;
		ll sum=0;
		for(int j=1;j<=n;j++)
			sum=sum+a[i][j];
		return sum;
	}
}
inline bool check(ll k){
	ll sum=0;
	for(int i=1;i<=n;i++) sum+=b[i][i];
	if(sum!=k) return 0;
	sum=0;
	for(int i=1;i<=n;i++) sum+=b[i][n-i+1];
	if(sum!=k) return 0;
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=1;j<=n;j++) sum+=b[i][j];
		if(sum!=k) return 0;
	}
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=1;j<=n;j++) sum+=b[j][i];
		if(sum!=k) return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]),b[i][j]=a[i][j];
	if(n==1){
		puts("1");return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!a[i][j]) x=i,y=j;
	ll sum=get(),ans=sum;
//	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
		ans-=a[x][i];
	if(ans<=0) wrong();
	b[x][y]=ans;
	if(!check(sum)) wrong();
	cout<<ans<<endl;
	return 0;
}