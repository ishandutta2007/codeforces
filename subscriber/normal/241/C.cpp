#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int h1,h2,n,v[222],w[222],xx,ans=0,s,q[211111],qq[222222],a,b,u;
double t1,t2,x,y,dy,d;
char t[222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> h1 >> h2 >> n;
	for (int i=0;i<n;i++){
		cin >> v[i] >> t[i] >> a >> b;
		for (int j=a;j<=b;j++){
			if (t[i]=='T')q[j]=i+1;else qq[j]=i+1;
		}
	}
	for (int gg=0;gg<2;gg++)for (int g=0;g<2;g++)for (int uu=0;uu<2;uu++)for (int ww=-1500;ww<1500;ww++){
		dy=ww*100;
		if (g)dy-=h1;else dy+=h1;
		if (gg)dy-=h2;else dy+=h2;
		dy=fabs(dy);
		d=100000;
		u=uu;
		x=0;
		y=h1;
		for (int i=0;i<n;i++)w[i]=0;
		s=0;
		for(;;){
			if (u){
				t1=(100000-x)/d;
				t2=(100-y)/dy;	
				if (t1<t2){
					y=y+dy*t1;
					if (fabs(y-h2)<1e-10)ans=max(ans,s);
					break;
				}else{
					x+=d*t2;
					y=100;
					u=0;
					xx=x+1e-11;
					if (!q[xx]||w[q[xx]-1])break;
					w[q[xx]-1]=1;
					s+=v[q[xx]-1];
				}
			}else{
				t1=(100000-x)/d;
				t2=y/dy;
				if (t1<t2){
					y=y-dy*t1;
					if (fabs(y-h2)<1e-10)ans=max(ans,s);
					break;
				}else{
					x+=d*t2;
					y=0;
					u=1;
					xx=x+1e-11;
					if (!qq[xx]||w[qq[xx]-1])break;
					w[qq[xx]-1]=1;
					s+=v[qq[xx]-1];
				}
			}
		}
	}
	CC(ans);
	return 0;
}