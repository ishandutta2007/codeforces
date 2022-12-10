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

const int N=1000000+19;

int n,k;
int A[N];
int l,r,res=-1;

bool check(int x){
	ll tmp=0;
	For(i,1,n+1){
		int v=A[i];
		ll a=1,b=0,A,B,mx=0;
		while (v+1>=x){
			if (v>=x) mx=max(mx,a+b);else mx=max(mx,b);
			if (v==0) break;
			if (v&1){
				A=a;
				B=a+2*b;
			} else{
				A=2*a+b;
				B=b;
			}
			a=A,b=B,v/=2;
		}
		tmp+=mx;
		if (tmp>=k) return 1;
		if (tmp+mx*(n-i)<k) return 0;
	}
	return 0;
}

int main(){
	n=IN(),k=IN();
	For(i,1,n+1) A[i]=IN();
	sort(A+1,A+n+1,greater<int>());
	l=1,r=int(1e7);
	while (l<=r){
		int mid=(l+r>>1);
		if (check(mid)) res=mid,l=mid+1;else r=mid-1;
	}
	printf("%d\n",res);
}