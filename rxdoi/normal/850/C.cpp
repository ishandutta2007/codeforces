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

const int N=100+19;

int A[N],B[N];
int n,res;
set<int> S;
map<set<int>,int> M;

int dfs(set<int> S){
	if (S.empty()) return 0;
	if (M.count(S)) return M[S];
	int mx=*--S.end();
	int vis[35];
	int &ans=M[S];
	memset(vis,0,sizeof(vis));
	For(i,1,mx+1){
		set<int> T;
		for (int j:S) T.insert(j>=i?j-i:j);
		vis[dfs(T)]=1;
	}
	for (;vis[ans];ans++);
	return ans;
}
int Work(int p){
	set<int> S;
	For(i,1,n+1){
		int c=0;
		while (A[i]%p==0) A[i]/=p,c++;
		if (c) S.insert(c);
	}
	return dfs(S);
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=B[i]=IN();
	For(i,1,n+1){
		for (int x=2;x*x<=B[i];x++)
			if (B[i]%x==0){
				S.insert(x);
				while (B[i]%x==0) B[i]/=x;
			}
		if (B[i]>1){
			S.insert(B[i]);
		}
	}
	for (int p:S) res^=Work(p);
	puts(res?"Mojtaba":"Arpa");
}