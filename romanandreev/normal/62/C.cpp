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
typedef double ld;
typedef pair<int,int> pi;
vector<ld> vx;
const ld eps=1e-8;
struct pnt{
	ld x,y;
	pnt(){
	}
	pnt(ld _x,ld _y){
		x=_x;
		y=_y;
	}
};
struct line{
	ld a,b,c;
	line(){
	}
	line(ld _x,ld _y,ld _z){
		a=_x;
		b=_y;
		c=_z;
	}
};
pnt scanfp(){
	ld x,y;
	cin>>x>>y;
	ld alp=0.4272396154;
	return pnt(x*cos(alp)-y*sin(alp),x*sin(alp)+y*cos(alp));
	//return pnt(x,y);
}
line p2l(pnt a,pnt b){
	ld A=b.y-a.y;
	ld B=a.x-b.x;
	ld C=-(A*a.x+B*a.y);
	return line(A,B,C);
}
void l2p(line a,line b){
	ld dd=a.a*b.b-a.b*b.a;
	ld dx=a.c*b.b-a.b*b.c;
	if (abs(dd)>eps){
		vx.pb(-dx/dd);
	}	               	
}
ld sp(pnt a,pnt b){
	return a.x*b.x+a.y*b.y;
}
ld dst(pnt a){
	return sqrt(sp(a,a));
}
pnt p[4][1000];
ld ff[1000];
int b[1000];
int main(){
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		p[0][i]=scanfp();
		p[1][i]=scanfp();
		p[2][i]=scanfp();
		p[3][i]=p[0][i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<3;j++){
			for (int i1=0;i1<n;i1++){
				for (int j1=0;j1<3;j1++){
					l2p(p2l(p[j][i],p[j+1][i]),p2l(p[j1][i1],p[j1+1][i1]));
				}	
			}
		}	
	}
	sort(vx.begin(),vx.end());
	/*for (int i=0;i<vx.size()-1;i++){
		cout<<vx[i]<<" "<<vx[i+1]<<endl;
	}*/
	ld ans=0,pp1y,pp2y;
	vector<pair<ld,int> > K;
	for (int i=0;i<(int)vx.size()-1;i++) if (abs(vx[i]-vx[i+1])>eps){
		K.clear();
		for (int j=0;j<n;j++){
			for (int k=0;k<3;k++){
				if ((p[k][j].x<=vx[i]+eps && p[k+1][j].x>=vx[i+1]-eps) || (p[k+1][j].x<=vx[i]+eps && p[k][j].x>=vx[i+1]-eps)){
					pp1y=p[k][j].y+(p[k+1][j].y-p[k][j].y)*(vx[i]-p[k][j].x)/(p[k+1][j].x-p[k][j].x);
					pp2y=p[k][j].y+(p[k+1][j].y-p[k][j].y)*(vx[i+1]-p[k][j].x)/(p[k+1][j].x-p[k][j].x);
					K.pb(mp((pp1y+pp2y)/2,j*3+k));
					ff[j*3+k]=sqrt((pp1y-pp2y)*(pp1y-pp2y)+(vx[i+1]-vx[i])*(vx[i+1]-vx[i]));	
				}
				b[j]=0;
			}
		}
		sort(K.begin(),K.end());
		int tk=0;
		for (int j=0;j<(int)K.size();j++){
			if (b[K[j].sc/3]==0 && tk==0){
				ans+=ff[K[j].sc];
				//cerr<<"S "<<vx[i]<<" "<<vx[i+1]<<" "<<K[j].sc/3<<" "<<K[j].sc%3<<endl;
			}
			if (b[K[j].sc/3]==1 && tk==1){
				ans+=ff[K[j].sc];
				//cerr<<"E "<<vx[i]<<" "<<vx[i+1]<<" "<<K[j].sc/3<<" "<<K[j].sc%3<<endl;
			}
			if (b[K[j].sc/3]==0){
				b[K[j].sc/3]=1;
				tk++;
			} else {
				b[K[j].sc/3]=0;
				tk--;
			}
		}
	}
	printf("%.18lf\n",(double)ans);
    return 0;
}