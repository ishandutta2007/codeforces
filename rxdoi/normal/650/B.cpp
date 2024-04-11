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
#define fir first
#define sec second
#define Mid (L+R>>1)

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

const int N=5e5+19;

ll fl[N],fr[N];
int n,a,b,T,res=1;
char s[N];

int getr(int L,int R,ll v){
	int res=R+1;
	while (L<=R){
		if (fr[Mid]<=v) res=Mid,R=Mid-1;else L=Mid+1;
	}
	return res;
}
int getl(int L,int R,ll v){
	int res=L-1;
	while (L<=R){
		if (fl[Mid]<=v) res=Mid,L=Mid+1;else R=Mid-1;
	}
	return res;
}

int main(){
	n=IN(),a=IN(),b=IN(),T=IN();
	scanf("%s",s+1);
	//fl[1]=fr[n+1]=(s[1]=='w')*b+1;
	for (int i=2;i<=n;i++){
		fl[i]=fl[i-1]+a+(s[i]=='w')*b+1;
	}
	for (int i=n;i>=2;i--){
		fr[i]=fr[i+1]+a+(s[i]=='w')*b+1;
	}
	if ((s[1]=='w')*b+1>T) return puts("0"),0;
	T-=(s[1]=='w')*b+1;
	if (fl[n]<=T) return printf("%d\n",n),0;
	for (int i=2;i<n;i++)
		if (fl[i]<=T){
			res=max(res,i+n-getr(i+1,n,T-fl[i]-(i-1)*a)+1);
		}
	for (int i=n;i>2;i--)
		if (fr[i]<=T){
			res=max(res,n-i+2+getl(2,i-1,T-fr[i]-(n-i+1)*a)-1);
		}
	printf("%d\n",res);
}