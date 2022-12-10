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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int p=1e6+3;
const int q=p-1;

ll n,k,tmp;
int a,b,num;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int main(){
	n=IN(),k=IN();
	if (n<=60&&k>1ll<<n){
		puts("1 1");
		return 0;
	}
	a=1;
	for (ll i=0;i<k&&a;i++){
		if (i==0){
			num=(num+n)%q;
		} else{
			ll x=n,y=i;
			while (y%2==0) x--,y/=2,num=(num+1)%q;
			x%=q,y%=p;
			a=1ll*a*(Pow(2,x)-y+p)%p;
		}
	}
	if (a==0){
		k--;num=1ll*(n%q)*(k%q)%q;
		while (k) num=(num-k/2+q)%q,k/=2;
		printf("%d %d\n",Pow(2,num),Pow(2,num));
	} else{
		b=Pow(2,(1ll*(n%q)*(k%q)%q-num+q)%q);
		printf("%d %d\n",(b-a+p)%p,b);
	}
}