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
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const db eps=1e-8;

struct Point{
	db x,y;
	bool operator < (const Point &B) const{
		return x<B.x-eps||fabs(x-B.x)<eps&&y<B.y;
	}
};
vector<Point> V,T;

struct Circle{
	int x,y,r;
	Point cal(db w){
		return (Point){x+r*cos(w),y+r*sin(w)};
	}
} O[5];

int fa[5];
int n,ans;

bool cmp(Point A,Point B){
	return fabs(A.x-B.x)<eps&&fabs(A.y-B.y)<eps;
}
int check(Circle A,Circle B){
	int dis=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
	int l=(A.r-B.r)*(A.r-B.r),r=(A.r+B.r)*(A.r+B.r);
	if (dis<l||dis>r) return 0;
	if (dis==l||dis==r) return 1;
	return 2;
}
db dis(Point A,Point B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
void work(Circle A,Circle B,vector<Point> &V){
	if (!check(A,B)) return;
	db d=dis((Point){A.x,A.y},(Point){B.x,B.y});
	db a=acos((A.r*A.r+d*d-B.r*B.r)/(2*A.r*d));
	db b=atan2(B.y-A.y,B.x-A.x);
	V.pb(A.cal(b+a));
	V.pb(A.cal(b-a));
}

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) fa[x]=y;
}

int main(){
	n=IN();
	For(i,1,n+1) O[i]=(Circle){IN(),IN(),IN()};
	if (n==1){
		printf("%d\n",2);
	} lf (n==2){
		if (check(O[1],O[2])==2){
			printf("%d\n",4);
		} else{
			printf("%d\n",3);
		}
	} lf (n==3){
		For(i,1,n+1) fa[i]=i;
		ans=1;
		For(i,1,n+1){
			T.clear();
			For(j,1,n+1) if (j!=i){
				if (check(O[i],O[j])) Union(i,j);
				work(O[i],O[j],V);
				work(O[i],O[j],T);
			}
			sort(T.begin(),T.end());
			T.resize(unique(T.begin(),T.end(),cmp)-T.begin());
			ans+=T.size();
		}
		sort(V.begin(),V.end());
		V.resize(unique(V.begin(),V.end(),cmp)-V.begin());
		//for (Point P:V) printf("(%.10lf,%.10lf)\n",P.x,P.y);
		ans-=V.size();
		For(i,1,n+1) if (fa[i]==i) ans++;
		printf("%d\n",ans);
	}
}