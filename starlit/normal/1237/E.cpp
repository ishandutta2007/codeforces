#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int main(){
	scanf("%d",&n);
	for(x=1,y=2;x<=n||y<=n;){
		if(x==n||y==n)return puts("1"),0;
		//cerr<<x<<','<<y<<endl;
		x+=y+1,y+=y+1;
		swap(x,y);
	}
	puts("0");
}