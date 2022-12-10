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

const int N=100+19;

int A[N],vis[N];
int n,x;
ll res=1;

ll lcm(ll a,ll b){
	return a/__gcd(a,b)*b;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1)
		if (!vis[i]){
			int x=A[i],len=1;
			vis[i]=1;
			for (;!vis[x];x=A[x]) vis[x]=1,len++;
			if (x!=i) return puts("-1"),0;
			res=lcm(res,len&1?len:len/2);
		}
	cout<<res<<endl;
}