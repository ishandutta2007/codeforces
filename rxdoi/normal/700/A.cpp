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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

int n,k;
db l,r,L,v1,v2;

bool check(db T){
	db t=0,x,y=0,tmp;
	int z=n/k+(n%k!=0);
	For(i,0,z){
		x=t*v1;
		if (x<y){
			tmp=(y-x)/(v1+v2);
			t+=tmp;
			if (t>T) return 0;
			x=y=x+tmp*v1;
		} else{
			tmp=(x-y)/(v2-v1);
			t+=tmp;
			if (t>T) return 0;
			x=y=x+tmp*v1;
		}
		if ((L-x)/(T-t)<=v1) return 1;
		tmp=(L-x-v1*(T-t))/(v2-v1);
		if (t+tmp>T) return 0;
		t+=tmp,y+=tmp*v2;
	}
	return 1;
}

int main(){
	n=IN(),L=IN(),v1=IN(),v2=IN(),k=IN();
	l=0,r=1.0*L/v1;
	For(i,0,50){
		db mid=(l+r)/2.0;
		if (check(mid)) r=mid;else l=mid;
	}
	printf("%.20lf\n",l);
}