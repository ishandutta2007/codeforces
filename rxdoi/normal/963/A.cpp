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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;
const int p=1e9+9;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int n,a,b,k,tmp,g,res;
char s[N];

int main(){
	n=IN(),a=IN(),b=IN(),k=IN();
	scanf("%s",s);
	k=min(k,n+1);
	For(i,0,k){
		int val=1ll*Pow(a,p-1-i)*Pow(b,i)%p;
		if (s[i]=='+') tmp=(tmp+val)%p;else tmp=(tmp-val+p)%p;
	}
	g=1ll*Pow(a,p-1-k)*Pow(b,k)%p;
	if (g!=1){
		res=1ll*tmp*(1-Pow(g,(n+1)/k)+p)%p*Pow(1-g+p,p-2)%p;
	} else{
		res=1ll*tmp*((n+1)/k)%p;
	}
	res=1ll*res*Pow(a,n)%p;
	printf("%d\n",res);
}