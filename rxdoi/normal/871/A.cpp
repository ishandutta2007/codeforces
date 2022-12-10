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

int main(){
	for (int q=IN();q--;){
		int n=IN();
		if (n%4==0){
			printf("%d\n",n/4);
		} lf (n%4==1){
			if (n<=5) puts("-1");else printf("%d\n",(n-5)/4);
		} lf (n%4==2){
			if (n<=2) puts("-1");else printf("%d\n",(n-2)/4);
		} lf (n%4==3){
			if (n<=11) puts("-1");else printf("%d\n",(n-7)/4);
		}
	}
}