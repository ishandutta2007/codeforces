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

const int oo=(1<<30)-1;

Vi rem,V[5][5];
int mn,mx,val,x,y,T;

bool check(int x){
	static int A[10];
	For(i,0,10) A[i]=0;
	For(i,0,4) A[x%10]++,x/=10;
	For(i,0,10) if (A[i]>1) return 0;
	return 1;
}
void calc(int val){
	static int A[10];
	For(j,0,5) For(k,0,5) V[j][k].clear();
	for (int x:rem){
		int a=0,b=0;
		For(i,0,10) A[i]=0;
		for (int i=0,z=val;i<4;i++) A[z%10]++,z/=10;
		for (int i=0,y=x,z=val;i<4;i++){
			if (y%10==z%10) a++;else if (A[y%10]) b++;
			y/=10,z/=10;
		}
		V[a][b].pb(x);
	}
}

int main(){
	For(i,0,10000){
		if (check(i)) rem.pb(i);
	}
	while (rem.size()>1){
		if (++T==1){
			val=123;
		} else{
			mn=oo;
			For(i,0,10000){
				calc(i);
				mx=0;
				For(j,0,5) For(k,0,5) mx=max(mx,int(V[j][k].size()));
				if (mx<mn){
					mn=mx;val=i;
				}
			}
		}
		printf("%04d\n",val);
		fflush(stdout);
		calc(val);
		x=IN(),y=IN();
		if (x==4&&y==0) return 0;
		rem=V[x][y];
	}
	printf("%04d\n",rem[0]);
}