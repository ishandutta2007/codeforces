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

const int top=200000;
const int N=200000+19;

int A[N];
int n;
ll res;

int main(){
	n=IN();
	For(i,1,n+1) A[IN()]++;
	For(i,1,top+1) A[i]+=A[i-1];
	For(i,1,top+1)
		if (A[i]-A[i-1]){
			ll tmp=0;
			for (int j=i;j<=top;j+=i) tmp+=1ll*j*(A[min(j+i-1,top)]-A[j-1]);
			res=max(res,tmp);
		}
	printf("%I64d\n",res);
}