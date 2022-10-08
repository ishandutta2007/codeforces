#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
struct pnt{
	ld x,y,z;
	pnt(){}
	pnt(ld _x,ld _y,ld _z){
		x=_x;
		y=_y;
		z=_z;
	}
};
pnt v(pnt a,pnt b){
	return pnt(b.x-a.x,b.y-a.y,b.z-a.z);
}
ld sp(pnt a,pnt b){
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
ld len(pnt a){
	return sqrt(sp(a,a));
}
int n;
pnt p[100000];
pnt p0,pa;
int Vp,Vs;
bool can(ld tim){	
	pnt ps=p[0];
	ld tkt=0;
	bool rc=false;
	for (int i=0;i<n-1;i++){
		if (tkt+len(v(p[i],p[i+1]))/Vs>tim){
			ps=pnt(p[i].x+(tim-tkt)*Vs*v(p[i],p[i+1]).x/len(v(p[i],p[i+1])),
				   p[i].y+(tim-tkt)*Vs*v(p[i],p[i+1]).y/len(v(p[i],p[i+1])),
				   p[i].z+(tim-tkt)*Vs*v(p[i],p[i+1]).z/len(v(p[i],p[i+1])));
			rc=true;
			break;
		}
		tkt+=len(v(p[i],p[i+1]))/Vs;
	}
	if (!rc){
		ps=p[n-1];
	}
	//cerr<<tim<<endl;
	//cerr<<ps.x<<" "<<ps.y<<" "<<ps.z<<endl; 
	//cerr<<p0.x<<" "<<p0.y<<" "<<p0.z<<endl; 
	pa=ps;
	if (len(v(p0,ps))/Vp<=tim){
		return true;
	} else 
		return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	scanf("%d",&n);
	n++;
	int xx,yy,zz;
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&xx,&yy,&zz);
		p[i]=pnt(xx,yy,zz);
	}
	scanf("%d%d",&Vp,&Vs);
	scanf("%d%d%d",&xx,&yy,&zz);
	p0=pnt(xx,yy,zz);
	ld ll=0;
	ld rr=0;
	ld mm;
	for (int i=0;i<n-1;i++){
		rr+=len(v(p[i],p[i+1]))/Vs;
	}
	for (int it=0;it<=100;it++){
		mm=(ll+rr)/2;	
		//cerr<<mm<<endl;
		if (can(mm)){
			rr=mm;
		} else 
			ll=mm;
	}
	if (can(rr)){
		printf("YES\n");
		printf("%.18lf\n",(double)ll);
		printf("%.18lf %.18lf %.18lf\n",(double)pa.x,(double)pa.y,(double)pa.z);
	} else 
		printf("NO\n");
    return 0;
}