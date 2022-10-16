#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-6;
const db pi=acos(-1);
int sign(db k){
	if (k>eps) return 1;
	else if (k<-eps) return -1;
	return 0;
}
int cmp(db k1,db k2){
	return sign(k1-k2);
}
int inmid(db k1,db k2,db k3){
	return sign(k1-k3)*sign(k2-k3)<=0;
}
struct point{
	db x,y;
	point operator + (const point &k1) const{return (point){k1.x+x,k1.y+y};}
	point operator - (const point &k1) const{return (point){x-k1.x,x-k1.y};}
	point operator * (db &k1) const{return (point){x*k1,y*k1};}
	point operator / (db &k1) const{return (point){x/k1,y/k1};}
	int operator == (const point &k1) const{return cmp(x,k1.x)==0 && cmp(y,k1.y)==0;}
	db abs(){return sqrt(x*x+y*y);}
	db abs2(){return x*x+y*y;}
	db dis(point k1){return ((*this)-k1).abs();}
};
struct osc{
	db ang;
	int v;
};
bool osccmp(osc a,osc b){
	int res=cmp(a.ang,b.ang);
	if (res==-1) return 1;
	if (res==0 && a.v>b.v) return 1;
	return 0;
}

int n,K;
int sz;
osc angle[400050];
point a[100050];

bool check(db R){
	sz=0;
	int now=0;
	for (int i=1;i<=n;i++){
		db d=a[i].abs()/2;
		if (cmp(d,R)==1) continue;
		db t=atan2(a[i].y,a[i].x);
		if (t<0) t+=2*pi;
		db dt=acos(d/R);
		db f=t-dt,s=t+dt;
		if (cmp(f,0.0)==-1) f+=2*pi;
		if (cmp(s,2*pi)==1) s-=2*pi;
		if (cmp(f,s)==1 || cmp(f,0.0)==0) now++;
		angle[++sz]=(osc){f,1};
		angle[++sz]=(osc){s,-1};
	}
	sort(angle+1,angle+sz+1,osccmp);
	for (int i=1;i<=sz;i++){
		now+=angle[i].v;
		if (now>=K) return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> K;
	for (int i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		if (x==0 && y==0){
			K--;
			i--;
			n--;
			continue;
		}
		a[i]=(point){(db)x,(db)y};
	}
	if (K<=0){
		cout << fixed << setprecision(10) << 0.0 << '\n';
		return 0;
	}
	db l=0,r=200000;
	for (int round=1;round<=100;round++){
		db mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	cout << fixed << setprecision(10) << l << '\n';
//	cout << fixed << setprecision(10) << sqrt(10) << '\n';
	return 0;
}