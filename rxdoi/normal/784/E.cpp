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

int a,b,c,d,e,f,g,h,i,j,k;

int cal(int x,int y,int f){
	if (f==2) return x|y;
	if (f==1) return x&y;
	if (f==0) return x^y;
}

int main(){
	a=IN(),b=IN(),c=IN(),d=IN();
	e=cal(a,b,0);
	f=cal(c,d,2);
	g=cal(b,c,1);
	h=cal(a,d,0);
	i=cal(e,f,1);
	j=cal(g,h,2);
	k=cal(i,j,0);
	printf("%d\n",k);
}