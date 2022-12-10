#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

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
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;
const int oo=(1<<30)-1;

int A[N],F[N];
int a,b,h,w,n,res=oo;

void Upd(int &x,int y){
	if (y>x) x=y;
}
int cal(int a,int b,int h,int w){
	memset(F,0,sizeof(F));
	F[min(a,h)]=b;
	if (F[h]>=w) return 0;
	for (int i=1;i<=n&&i<=60;i++){
		for (int j=h;j>=min(a,h);j--){
			Upd(F[min(1ll*j*A[i],0ll+h)],F[j]);
			Upd(F[j],min(1ll*F[j]*A[i],0ll+w));
		}
		if (F[h]>=w) return i;
	}
	return oo;
}

int main(){
	a=IN(),b=IN(),h=IN(),w=IN(),n=IN();
	For(i,1,n+1) A[i]=IN();
	sort(A+1,A+n+1,greater<int>());
	res=min(res,cal(h,w,a,b));
	res=min(res,cal(w,h,a,b));
	printf("%d\n",res==oo?-1:res);
}