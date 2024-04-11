#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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

const int N=200000+19;

struct QType{
	int i,l,r;
};vector<QType> I[N],O[N];

struct Rect{
	int x1,y1,x2,y2;
} R[N];
int A[N],B[N],vis[N];
int n,ans;

int mn[N*8],mx[N*8];
set<int> s[N*4];
int Ql,Qr,id,opt;

void upd(int x){
	mn[x]=min(mn[Lsn],mn[Rsn]);
	mx[x]=max(mx[Lsn],mx[Rsn]);
	if (!s[x].empty()){
		int tmp=*--s[x].end();
		mn[x]=max(mn[x],tmp);
		if (tmp>mx[x]) mx[x]=0;
		if (tmp>=mn[x]&&!vis[tmp]){
			mx[x]=max(mx[x],tmp);
		}
	}
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		if (opt==1){
			s[x].insert(id);
		} lf (opt==2){
			s[x].erase(id);
		}
		upd(x);
		return;
	}
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	upd(x);
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	n=IN();
	For(i,1,n+1){
		R[i]=(Rect){IN(),IN(),IN(),IN()};
		A[++*A]=R[i].x1;
		A[++*A]=R[i].x2;
		B[++*B]=R[i].y1;
		B[++*B]=R[i].y2;
	}
	sort(A+1,A+*A+1);
	*A=unique(A+1,A+*A+1)-A-1;
	sort(B+1,B+*B+1);
	*B=unique(B+1,B+*B+1)-B-1;
	For(i,1,n+1){
		R[i].x1=lower_bound(A+1,A+*A+1,R[i].x1)-A;
		R[i].x2=lower_bound(A+1,A+*A+1,R[i].x2)-A-1;
		R[i].y1=lower_bound(B+1,B+*B+1,R[i].y1)-B;
		R[i].y2=lower_bound(B+1,B+*B+1,R[i].y2)-B-1;
		I[R[i].x1].pb((QType){i,R[i].y1,R[i].y2});
		O[R[i].x2].pb((QType){i,R[i].y1,R[i].y2});
	}
	For(w,1,*A+1){
		for (QType T:I[w]){
			id=T.i;
			Ql=T.l;
			Qr=T.r;
			opt=1;
			Modify(1,1,*B);
		}
		while (mx[1]){
			vis[mx[1]]=1;
			Ql=R[mx[1]].y1;
			Qr=R[mx[1]].y2;
			opt=3;
			Modify(1,1,*B);
			ans++;
		}
		for (QType T:O[w]){
			id=T.i;
			Ql=T.l;
			Qr=T.r;
			opt=2;
			Modify(1,1,*B);
		}
	}
	printf("%d\n",ans+1);
}