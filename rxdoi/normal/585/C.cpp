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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

ll x,y;

void Work(ll x,ll y){
	if (x==y) return;
	if (x==1) printf("%I64dB",y-1);else
	if (y==1) printf("%I64dA",x-1);else
	if (x>y){
		printf("%I64dA",x/y);
		Work(x%y,y);
	} else{
		printf("%I64dB",y/x);
		Work(x,y%x);
	}
}

int main(){
	scanf("%I64d%I64d",&x,&y);
	if (__gcd(x,y)>1){
		puts("Impossible");
		return 0;
	}
	Work(x,y);
	puts("");
}