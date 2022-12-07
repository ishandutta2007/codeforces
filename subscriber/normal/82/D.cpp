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

int w[1111][1111],ww[1111][1111],n,a[1111];

int rec(int x,int y){
	if (y==n)return a[x];
	if (y+1==n)return max(a[x],a[y]);
	if (w[x][y])return ww[x][y];
	w[x][y]=1;
	int r=min(rec(x,y+2)+max(a[y],a[y+1]),rec(y,y+2)+max(a[x],a[y+1]));
	r=min(r,rec(y+1,y+2)+max(a[x],a[y]));
	ww[x][y]=r;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	cout << rec(0,1) << endl;
	int x=0;
	int y=1;
	for(;;){
		if (y==n){
			cout << x+1 << endl;
			return 0;
		}
		if (y+1==n){
			cout << x+1 << " " << y+1 << endl;
			return 0;
		}
		int r=min(rec(x,y+2)+max(a[y],a[y+1]),rec(y,y+2)+max(a[x],a[y+1]));
		r=min(r,rec(y+1,y+2)+max(a[x],a[y]));
		if (r==rec(x,y+2)+max(a[y],a[y+1])){
			cout << y+1 << " " << y+2 << endl;
			y+=2;
		}else if (r==rec(y,y+2)+max(a[x],a[y+1])){
			cout << x+1 << " " << y+2 << endl;
			x=y;
			y+=2;
		}else{
			cout << x+1 << " " << y+1 << endl;
			x=y+1;
			y+=2;
		}

	}
	return 0;
}