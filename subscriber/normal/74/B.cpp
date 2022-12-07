#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,x,y,v,p[1111],w[211][211];
string s,g;

int rec(int t,int x){
	if (x==p[t])return 0;
	if (t==g.size()-1)return 1111111111;
	if (w[t][x])return w[t][x];
	int r=0;
	if (g[t]=='1'){
		for (int i=0;i<n;i++)r=max(r,rec(t+1,i));
	}else{
		if (x>0)if(p[t]!=x-1)r=max(r,rec(t+1,x-1));
		if (x<n-1)if(p[t]!=x+1)r=max(r,rec(t+1,x+1));
		r=max(r,rec(t+1,x));
	}
	r++;
//	cout << t << " " << x << " " << r << endl;
	w[t][x]=r;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> x >> y >> s >> s >> g;
	x--;
	y--;
	if (s[0]=='t')v=1;else v=-1;
	p[0]=y;
	for (int i=1;i<g.size();i++){
		if (p[i-1]+v<0||p[i-1]+v>=n)v*=-1;
		p[i]=p[i-1]+v;
	}
	int o=rec(0,x);         
	if (o>=1111111111)puts("Stowaway");else
	cout << "Controller " << o << endl;
	return 0;
}