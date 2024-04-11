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

int x,y,p,q;

int cal(int a,int b){
	return a/b+(a%b!=0);
}
ll Main(){
	x=IN(),y=IN(),p=IN(),q=IN();
	if (1ll*x*q==1ll*p*y) return 0;
	if (p==0||p==q) return -1;
	int k=max(cal(x,p),max(cal(y,q),cal(y-x,q-p)));
	return 1ll*k*q-y;
}

int main(){
	for (int T=IN();T--;){
		printf("%I64d\n",Main());
	}
}