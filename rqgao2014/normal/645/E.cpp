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

const int mod=1e9+7;
int n,m,k,last[255],dp[2000005],sum[2000005];
char s[2000005];

inline int youyl(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);m=strlen(s+1);
	dp[0]=1;sum[0]=1;
	memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++){
		int j=last[s[i]-'a'];
		dp[i]=(sum[i-1]-(j>0?sum[j-1]:0)+mod)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
		last[s[i]-'a']=i;
	}
	for(int i=m+1;i<=m+n;i++){
		int maxx=i,maxa=0;
		for(int a=0;a<k;a++)
			if(last[a]<maxx) maxx=last[a],maxa=a;
		dp[i]=(sum[i-1]-(maxx>0?sum[maxx-1]:0)+mod)%mod;last[maxa]=i;sum[i]=(sum[i-1]+dp[i])%mod;
	}
	printf("%d\n",sum[n+m]);
	return 0;
}

int main(){
	return youyl();
}