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

int n,t,k,d,ans1,ans2,l,r;

bool check(int T){
	return T/t*k+(T-d)/t*k>=n;
}

int main(){
	n=IN(),t=IN(),k=IN(),d=IN();
	ans1=(n/k+(n%k!=0))*t;
	l=d,r=ans1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;else l=mid+1;
	}
	puts(r+1<ans1?"YES":"NO");
}