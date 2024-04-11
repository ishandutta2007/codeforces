#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n,a[1000],xx[1000],yy[1000],pp[1000],kk=0,u=0,f[1000],x;

void add(int x,int y){
	yy[++kk]=y;
	pp[kk]=xx[x];
	xx[x]=kk;
	yy[++kk]=x;
	pp[kk]=xx[y];
	xx[y]=kk;
}

void rec(int x){
	if (f[x])return;
	f[x]=u;
	for (int w=xx[x];w;w=pp[w])rec(yy[w]);
}

int main(){
	memset(f,0,sizeof(f));
	memset(xx,0,sizeof(xx));
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++){
		cin >> x;
		if (i-x>=0)add(i,i-x);
		if (i+x<n)add(i,i+x);
	}
	for (int i=0;i<n;i++)if (!f[i]){
		u++;
		rec(i);
	}
	for (int i=0;i<n;i++)if (f[i]!=f[a[i]-1]){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}