#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

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

ll p,q,b;

void Main(){
	p=IN(),q=IN(),b=IN();
	ll t=__gcd(p,q);
	p/=t,q/=t;
	while ((t=__gcd(q,b))>1){
		while (q%t==0) q/=t;
	}
	if (q==1){
		puts("Finite");
	} else{
		puts("Infinite");
	}
}

int main(){
	for (int T=IN();T--;) Main();
}