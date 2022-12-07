#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>

using namespace std;

int n,a[5555],x,y,z,yy[22222],pp[22222],xx[5555],k=0,f[5555],ff[5555],tt[5555],hh[5555],ans[5555],zz[22222],kk=0;
map<int,int>M;
vector<int>v[5555];

void rec(int x,int pr,int s){
	if (f[x])return;
	f[x]=1;
	ff[k]=x;
	tt[k]=pr;
	hh[k++]=s;
	for (int w=xx[x];w;w=pp[w])rec(yy[w],x,zz[w]);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)M[a[i]]=i;
	for (int i=1;i<n;i++){
		cin >> x >> y >> z;
		x--;
		y--;
		yy[++kk]=y;
		zz[kk]=z;
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		zz[kk]=z;
		pp[kk]=xx[y];
		xx[y]=kk;
	}
	rec(0,-1,-1);
	for (int i=1;i<n;i++)v[i].push_back(a[i]);
	for (int it=1;it<=n;it++){
		for (int i=1;i<k;i++){
			int x=min((int)v[ff[i]].size(),hh[i]);
			for (int j=0;j<x;j++)v[tt[i]].push_back(v[ff[i]][j]);
			for (int j=0;j<x;j++){
				v[ff[i]][j]=v[ff[i]][v[ff[i]].size()-1];
				v[ff[i]].pop_back();
			}
		}
		for (int i=0;i<v[0].size();i++)ans[M[v[0][i]]]=it;
		v[0].clear();
		for (int i=1;i<n;i++)sort(v[i].begin(),v[i].end());
	}
	for (int i=0;i<n-1;i++)cout << ans[i] << " ";
	cout << ans[n-1] << endl;
	return 0;
}