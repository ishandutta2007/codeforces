#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

map<pair<int,int>, int> me;
int a,b,n;

long long pow(int x,int y){
	if (x==1)return 1;
	long long r=1;
	for (int i=0;i<y;i++){
		r*=x;
		if (r>=n)break;
	}
	return r;
}

int f(int x,int y){
	if (pow(x,y)>=n)return 1;
	if (x==1&&pow(2,y)>=n)return 2;
	if (y==1&&pow(x,2)>=n){
		if ((n-x)%2==1)return 3;else return 1;
	}
	if (me[make_pair(x,y)])return me[make_pair(x,y)];
	int l1=f(x+1,y);
	int l2=f(x,y+1);
	int r=3;
	if (l1==3||l2==3)r=1;else if (l1==2||l2==2)r=2;
	me[make_pair(x,y)]=r;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> a >> b >> n;
	int q=f(a,b);
	if (q==1)puts("Masha");else if (q==2)puts("Missing");else puts("Stas");
	return 0;
}