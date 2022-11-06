#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

const int MAXN=10000000;

int D[MAXN+10];
int ans[MAXN+10];
char mu[MAXN+10];
int n;
int pow2[600010];
const int mod=1000000007;

int main(){
	pow2[0]=1;
	REP_1(i,500100){
		pow2[i]=pow2[i-1]<<1;
		if(pow2[i]>=mod) pow2[i]-=mod;
	}
	mu[1]=-1;
	REP_1(i,MAXN) if(mu[i]){
		for(int j=i+i;j<=MAXN;j+=i){
			mu[j]-=mu[i];
		}
	}
	mu[1]=0;
	scanf("%d",&n);
	REP_1(i,n){
		int x;
		scanf("%d",&x);
		++D[x];
	}
	LL sumall=0;
	REP_1(i,MAXN) if(mu[i]){
		int num=0;
		for(int j=i;j<=MAXN;j+=i){
			num+=D[j];
		}
		num=pow2[num]-1;
		if(mu[i]==-1&&num) num=mod-num;
		sumall+=num;
		if(sumall>=mod) sumall-=mod;
		for(int j=i;j<=MAXN;j+=i){
			ans[j]+=num;
			if(ans[j]>=mod) ans[j]-=mod;
		}
	}
	int anss=0;
	REP_1(i,MAXN){
		if(D[i]){
			REP_1(j,D[i]){
				anss+=(sumall-ans[i])%mod;
				if(anss>=mod)anss-=mod;
				if(anss<0) anss+=mod;
			}
		}
	}
	printf("%d\n",anss);
	scanf("%d",&n);
	return 0;
}