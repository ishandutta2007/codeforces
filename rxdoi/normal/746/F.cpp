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

const int N=2e5+19;

int A[N],T[N],vis[N];
int n,w,k,l,r;
int sumT,sumA;
int res;

struct node{
	int x;
	bool operator < (const node &B) const{
		return T[x]>T[B.x]||T[x]==T[B.x]&&x<B.x;
	}
};set<node> S,S2;

void Del(int x){
	if (vis[x]){
		vis[x]=0;
		sumT+=T[x]/2;
		S2.erase(S2.find((node){x}));
		if (!S.empty()){
			int x=S.begin()->x;
			vis[x]=1;
			sumT-=T[x]/2;
			S2.insert(*S.begin());
			S.erase(*S.begin());
		} else{
			w++;
		}
	} else{
		S.erase(S.find((node){x}));
	}
	sumT-=T[x];
	sumA-=A[x];
}
bool Ins(int x){
	sumT+=T[x];
	sumA+=A[x];
	if (!S2.empty()&&(node){x}<*--S2.end()){
		int y=(--S2.end())->x;
		vis[x]=1;
		vis[y]=0;
		S2.erase(--S2.end());
		S.insert((node){y});
		S2.insert((node){x});
		sumT+=T[y]/2;
		sumT-=T[x]/2;
	} else{
		S.insert((node){x});
	}
	if (sumT<=k) return 1;
	while (w&&sumT>k&&!S.empty()){
		int x=S.begin()->x;
		S.erase(S.begin());
		S2.insert((node){x});
		sumT-=T[x]/2;
		vis[x]=1;
		w--;
	}
	if (sumT>k){
		Del(x);
		return 0;
	}
	return 1;
}

int main(){
	n=IN(),w=IN(),k=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) T[i]=IN();
	r=1;
	for (l=1;l<=n;l++){
		for (;r<=n&&Ins(r);) r++;
		if (l<r){
			res=max(res,sumA);
			Del(l);
		} else{
			r=l+1;
		}
	}
	printf("%d\n",res);
}