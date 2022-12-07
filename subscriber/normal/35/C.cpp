#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <time.h>

using namespace std;

int n,m,k,x,y,ans=0,ax,ay,f[2000][2000],qx[2000000],qy[2000000],q1=0,q2=0,l,ql[2000000];

void add(int x,int y,int l){
	if (x<0||x>=n||y<0||y>=m||f[x][y])return;
	f[x][y]=1;
	if (l>ans){
		ans=l;
		ax=x;
		ay=y;
	}
	qx[q1]=x;
	qy[q1]=y;
	ql[q1++]=l;
	if (q1==1999998)q1=0;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m >> k;
	for (int i=0;i<k;i++){
		cin >> x >> y;
		add(x-1,y-1,0);
	}
	while (q1!=q2){
		l=ql[q2];
		x=qx[q2];
		y=qy[q2++];
		if (q2==1999998)q2=0;
		add(x-1,y,l+1);
		add(x+1,y,l+1);
		add(x,y-1,l+1);
		add(x,y+1,l+1);
	}
	cout << ax+1 << " " << ay+1 << endl;
	return 0;
}