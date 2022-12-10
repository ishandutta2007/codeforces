#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=200000+19;

ll s[N],a[N],b[N],c[N];
ll sum,mn=1ll<<60;
int cnt[30];
int n;

bool check(){
	For(t,0,30){
		For(i,1,n+1) cnt[t]+=(a[i]>>t&1);
	}
	For(i,1,n+1){
		ll B=0,C=0;
		For(t,0,30)
			if (a[i]>>t&1){
				B+=cnt[t]<<t;
				C+=n<<t;
			} else{
				B+=0<<t;
				C+=cnt[t]<<t;
			}
		if (B!=b[i]||C!=c[i]) return 0;
	}
	return 1;
}

int main(){
	n=IN();
	For(i,1,n+1) b[i]=IN();
	For(i,1,n+1) c[i]=IN();
	For(i,1,n+1){
		s[i]=b[i]+c[i];
		sum+=s[i];
	}
	if (sum%(2*n)!=0){
		puts("-1");
		return 0;
	}
	sum/=2*n;
	For(i,1,n+1) s[i]-=sum;
	For(i,1,n+1)
		if (s[i]%n!=0){
			puts("-1");
			return 0;
		}
	For(i,1,n+1) a[i]=s[i]/n;
	if (!check()){
		puts("-1");
		return 0;
	}
	For(i,1,n+1){
		printf("%I64d ",a[i]);
	}
	puts("");
}