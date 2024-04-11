#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;
const ll inf=1e18;

struct Point{
	ll x,y;
	bool operator < (const Point &B) const{
		return x<B.x||x==B.x&&y<B.y;
	}
	ll At(int w) const{
		return x*w+y;
	}
};
typedef Point Vector;
typedef set<Point> Set;

Vector operator - (Point A,Point B){
	return (Vector){A.x-B.x,A.y-B.y};
}
db cross(Vector A,Vector B){
	return db(1.0)*A.x*B.y-db(1.0)*A.y*B.x;
}

struct Edge{
	int y,nxt;
} E[N*2];
int A[N],B[N],las[N];
int n,cnt;
ll ans[N];
Set pool[N],*S[N];

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void Ins(Set *A,Point P){
	Set::iterator it,it2;
	it=A->lower_bound((Point){P.x,-inf});
	if (it!=A->end()&&it->x==P.x){
		if (it->y<=P.y) return;
		A->erase(it);
	}
	it=A->upper_bound(P);
	if (it!=A->end()){
		it2=it;
		if (it2!=A->begin()){
			it2--;
			if (cross(P-*it2,*it-P)<=0) return;
		}
	}
	for (;;){
		it=A->upper_bound(P);
		if (it==A->begin()||(--it)==A->begin()) break;
		it2=it;--it2;
		if (cross(*it-*it2,P-*it)<=0) A->erase(it);else break;
	}
	for (;;){
		it=A->upper_bound(P);
		if (it==A->end()||it==--A->end()) break;
		it2=it;++it2;
		if (cross(*it-P,*it2-*it)<=0) A->erase(it);else break;
	}
	A->insert(P);
}
Set *Merge(Set *A,Set *B){
	if (A->size()>B->size()) swap(A,B);
	for (Point P:*B) Ins(A,P);
	return A;
}
ll calc(Set *A,int w){
	Set::iterator it,it2,v;
	int l=-int(1e5),r=int(1e5);
	while (l<=r){
		int mid=(l+r)/2;
		it=A->lower_bound((Point){mid,-inf});
		if (it==A->end()){
			r=mid-1;
		} lf (it!=--A->end()){
			it2=it,++it2;
			if (it->At(w)>it2->At(w)) l=mid+1;else v=it,r=mid-1;
		} else{
			v=it,r=mid-1;
		}
	}
	return v->At(w);
}
void dfs(int x,int fa){
	S[x]=pool+x;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
			S[x]=Merge(S[x],S[y]);
		}
	if (!S[x]->empty()){
		ans[x]=calc(S[x],A[x]);
		/*
		for (Point P:*S[x]){
			ans[x]=min(ans[x],P.At(A[x]));
		}
		*/
	} else{
		ans[x]=0;
	}
	Ins(S[x],(Point){B[x],ans[x]});
}

int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	For(i,1,n) Link(IN(),IN());
	dfs(1,-1);
	For(i,1,n+1) printf("%I64d ",ans[i]);
	puts("");
}