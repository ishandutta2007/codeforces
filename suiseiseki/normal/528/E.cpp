#include <algorithm>
#include <cstdio>
#include <cmath>
#define LD double
#define LL long long
#define Re register int
#define Vector Point
using namespace std;
const int N=3003;
const LD eps=1e-8;
int dcmp(LD a){
	return a<-eps?-1:(a>eps?1:0);
}
struct Point{
	LD x,y;
	Point(LD X=0,LD Y=0){
		x=X,y=Y;
	}
	void in(){
		scanf("%lf%lf",&x,&y);
	}
	void print(){
		printf("%.3lf %.3lf\n",x,y);
	}
};
void in(int &a){
	int f=1;
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
LD Dot(Vector a,Vector b){
	return a.x*b.x+a.y*b.y;
}
LD Cro(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}
LD Len(Vector a){
	return sqrt(Dot(a,a));
}
Vector operator +(Vector a,Vector b){
	return Vector(a.x+b.x,a.y+b.y);
}
Vector operator -(Vector a,Vector b){
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator *(Vector a,LD b){
	return Vector(a.x*b,a.y*b);
}
Point cross_LL(Point a,Point b,Point c,Point d){
    Vector x=b-a,y=d-c,z=a-c;
    return a+x*(Cro(y,z)/Cro(x,y));
}
int judge(Point a,Point L,Point R){
    return dcmp(Cro(L-a,R-a))>0;
}
struct Line{
	Point a,b;
	LD k;
	Line(Point A=Point(0,0),Point B=Point(0,0)){
		a=A;
		b=B;
		k=atan2(b.y-a.y,b.x-a.x);
	}
	friend bool operator <(Line p,Line q){
		return dcmp(p.k-q.k)?dcmp(p.k-q.k)<0:judge(q.a,q.b,p.a);
	}
}L[N];
Point cross(Line L1,Line L2){
	return cross_LL(L1.a,L1.b,L2.a,L2.b);
}
int n,a,b,c;
LD x,y,ans;
int main(){
	in(n);
	for(int i=1;i<=n;i++){
		in(a),in(b),in(c);
		if(!dcmp(a)){
			L[i]=Line(Point(0,(LD)c/b),Point(1,(LD)c/b));
		}
		else if(!dcmp(b)){
			L[i]=Line(Point((LD)c/a,0),Point((LD)c/a,1));
		}
		else{
			L[i]=Line(Point(0,(LD)c/b),Point(1,(LD)(c-a)/b));
		}
	}
	sort(L+1,L+1+n);
	for(int i=1;i<=n;i++){
		Point S,P;
		for(int j=i<n?i+1:1;j!=i;j=j<n?j+1:1){
			P=cross(L[i],L[j]),ans+=Cro(S,P),S=S+P;
		}
	}
	printf("%lf\n",ans*3/n/(n-1)/(n-2));
	return 0;
}