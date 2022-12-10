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

const int N=100000+19;

ll A[N],res;
int n;

void Work(int s){
	ll sum=0;
	for (int i=s;i<=n;i++){
		if (i%2==s%2) sum=max(sum,0ll);
		sum+=A[i];
		res=max(res,sum);
	}
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n) A[i]=abs(A[i+1]-A[i]);
	n--;
	for (int i=1;i<=n;i+=2) A[i]*=-1;
	Work(2);
	For(i,1,n+1) A[i]*=-1;
	Work(1);
	cout<<res<<endl;
}