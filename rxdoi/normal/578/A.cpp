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

int a,b,l,r,tmp;
db res=1e60;

void calc1(db T){
	if (T<0) return;
	l=0,r=1e9,tmp=-1;
	while (l<=r){
		int mid=(l+r>>1);
		if (T/(2ll*mid)>=b) tmp=mid,l=mid+1;else r=mid-1;
	}
	if (~tmp) res=min(res,T/(2ll*tmp));
}
void calc2(db T){
	l=1,r=1e9,tmp=-1;
	while (l<=r){
		int mid=(l+r>>1);
		if (T/(2ll*mid)>=b) tmp=mid,l=mid+1;else r=mid-1;
	}
	if (~tmp) res=min(res,T/(2ll*tmp));
}

int main(){
	a=IN(),b=IN();
	calc1(a-b);
	calc2(a+b);
	if (res<1e50){
		printf("%.10lf\n",res);
	} else{
		puts("-1");
	}
}