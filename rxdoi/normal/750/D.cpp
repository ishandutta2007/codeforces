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

const int N=30+19;
const int Top=5000000;

int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

struct node{
	int x,y,i,j,d;
	bool operator < (const node &B) const{
		if (x!=B.x) return x<B.x;
		if (y!=B.y) return y<B.y;
		if (i!=B.i) return i<B.i;
		if (j!=B.j) return j<B.j;
		if (d!=B.d) return d<B.d;
		return 0;
	}
} Q[Top];
map<node,int> M;
map<pii,int> M2;

int T[N];
int n,f,w;

int main(){
	n=IN();
	For(i,1,n+1) T[i]=IN();
	M[(node){0,0,1,1,1}]=1;
	M2[mp(0,0)]=1;
	Q[1]=(node){0,0,1,1,1};
	f=1,w=0;
	while (f>w){
		node A=Q[++w],B;
		if (A.j==T[A.i]){
			if (A.i==n) continue;
			B=A;B.d=(B.d+1)%8;
			B.x+=dx[B.d];
			B.y+=dy[B.d];
			B.i++;B.j=1;
			if (!M.count(B)) M[B]=1,Q[++f]=B;
			M2[mp(B.x,B.y)]=1;
			B=A;B.d=(B.d+7)%8;
			B.x+=dx[B.d];
			B.y+=dy[B.d];
			B.i++;B.j=1;
			if (!M.count(B)) M[B]=1,Q[++f]=B;
			M2[mp(B.x,B.y)]=1;
		} else{
			B=A;
			B.x+=dx[B.d];
			B.y+=dy[B.d];
			B.j++;
			if (!M.count(B)) M[B]=1,Q[++f]=B;
			M2[mp(B.x,B.y)]=1;
		}
	}
	printf("%d\n",M2.size());
}