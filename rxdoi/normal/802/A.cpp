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

const int N=400000+19;

int nxt[N],A[N],B[N],vis[N];
int n,k,res;
multiset<int> S;

int main(){
	n=IN(),k=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=n+1;
	for (int i=n;i;i--){
		nxt[i]=B[A[i]];
		B[A[i]]=i;
	}
	For(i,1,n+1){
		if (!vis[A[i]]){
			res++;
			if (S.size()==k){
				int x=*--S.end();
				S.erase(S.find(x));
				vis[A[x]]=0;
			}
			S.insert(nxt[i]);
			vis[A[i]]=1;
		} else{
			S.erase(S.find(i));
			S.insert(nxt[i]);
		}
	}
	printf("%d\n",res);
}