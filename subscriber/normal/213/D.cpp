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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

double R=sqrt(10)*sqrt(5+sqrt(5));
double pi=acos(-1);
double ax[555],ay[555];
int n,k;

void dr(int l,double x,double y){
	if (l==n)return;
	double yc=y-5;
	double xc=x+sqrt(R*R-5*5);
	double xx,yy;
	if (!k)ax[k]=x,ay[k++]=y;

	xx=xc+cos((pi+pi)/5)*R;
	yy=yc+sin((pi+pi)/5)*R;
	ax[k]=xx;ay[k++]=yy;

	xx=xc+cos((pi+pi)/5*3)*R;
	yy=yc+sin((pi+pi)/5*3)*R;
	ax[k]=xx;ay[k++]=yy;

	xx=xc+cos((pi+pi)/5*4)*R;
	yy=yc+sin((pi+pi)/5*4)*R;
	ax[k]=xx;ay[k++]=yy;

	xx=xc+R;
	yy=yc;
	ax[k]=xx;ay[k++]=yy;
	dr(l+1,xx,yy);
}

void dd(int l){
	if (l==n)return;
	int t=l*4+1;
	cout << " " << t+4;
	dd(l+1);
	cout << " " << t+2 << " " << t+1 << " " << t+3 << " " << t;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	dr(0,0,0);
	CC(k);
	for (int i=0;i<k;i++)printf("%.10lf %.10lf\n",ax[i],ay[i]);
	for (int i=0;i<n;i++){
		int t=i*4+1;
		cout << t << " " << t+2 << " " << t+3 << " " << t+4 << " " << t+1 << endl;
	}
	cout << 1;
	dd(0);
	puts("");
	return 0;
}