#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

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

const int N=4e5+19;
const int top=2e5;

struct Point{
	int x,y;
};
int n,x,y;
ll ans;

void upmax(int &x,int y){
	if (y>x) x=y;
}
void upmin(int &x,int y){
	if (y<x) x=y;
}

struct sol{
	Point P[N];
	int A0[N],B0[N],C0[N],D0[N];
	int *A=A0+N/2,*B=B0+N/2,*C=C0+N/2,*D=D0+N/2;
	int n,w;
	void Ins(int x,int y){
		P[++n]=(Point){x,y};
	}
	void work(){
		memset(A0,200,sizeof(A0));
		memset(B0,60,sizeof(B0));
		memset(C0,200,sizeof(C0));
		memset(D0,60,sizeof(D0));
		For(i,1,n+1){
			upmax(A[P[i].x+P[i].y-1],P[i].x-P[i].y-1);
			upmin(B[P[i].x+P[i].y+1],P[i].x-P[i].y+1);
			upmax(C[P[i].x+P[i].y+1],P[i].x-P[i].y-1);
			upmin(D[P[i].x+P[i].y-1],P[i].x-P[i].y+1);
		}
		for (int i=-top;i<=top;i++){
			upmin(B[i],B[i-1]);
			upmax(C[i],C[i-1]);
		}
		for (int i=top;i>=-top;i--){
			upmax(A[i],A[i+1]);
			upmin(D[i],D[i+1]);
		}
		for (int i=-top;i<=top;i++)
			if ((i&1)==w){
				int r=min(A[i],C[i]);
				int l=max(B[i],D[i]);
				if ((l&1)!=w) l++;
				if ((r&1)!=w) r--;
				if (l>r) continue;
				ans+=(r-l)/2+1;
			}
	}
} A,B;

int main(){
	A.w=0;
	B.w=1;
	n=IN();
	For(i,1,n+1){
		x=IN(),y=IN();
		if ((x+y)&1){
			A.Ins(x,y);
		} else{
			B.Ins(x,y);
		}
	}
	A.work();
	B.work();
	cout<<ans<<endl;
}