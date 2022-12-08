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
//#define rf random_shuffle
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

const int N=1000000,mod=1e9+7;
int ans,k,n,num[N+5],a[N+5],res[N+5];

int main(){
	read(n);read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);int x=a[i];
		if(x<=k) num[x]++;
	}
	int ans=0,ansx=1;
	for(int i=1;i<=k;i++){
		for(int j=i;j<=k;j+=i)
			res[j]+=num[i];
		if(ans<res[i])
			ans=res[i],ansx=i;
	}
	printf("%d %d\n",ansx,ans);
	for(int i=1;i<=n;i++)
		if(ansx%a[i]==0) printf("%d ",i);
	return 0;
}