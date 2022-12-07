#include <iostream>
#define N 111111

using namespace std;

int n,r1,r2,kk=0,yy[N],xx[N],pp[N],f[N],ans[N],x,y,o,l[N];

void rec(int x,int d){
	if (f[x])return;
	f[x]=1;
	ans[x]=d;
	for (int w=xx[x];w;w=pp[w])rec(yy[w],x);
}

int main(){
	cin >> n >> r1 >> r2;
	int x=0;
	for (int i=1;i<n;i++){
		if (i==r1)x++;
		cin >> y;
		y--;
		yy[++kk]=y;
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		pp[kk]=xx[y];
		xx[y]=kk;
		x++;
	}
	rec(r2-1,r2-1);
	for (int i=0;i<n;i++)if (i!=r2-1)cout << (ans[i]+1) << " ";
	return 0;
}