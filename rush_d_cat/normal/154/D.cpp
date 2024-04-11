#include <bits/stdc++.h>
using namespace std;

int x1,x2,a,b;
void solve1(int x1,int x2,int a,int b){
	// x1<x2, [a,b]
	int n=x2-x1;
	if(a<=0){
		if(n<=b){
			printf("FIRST\n%d\n", x2);
		} else {
			printf("DRAW\n");
		}
		return;
	}
	int pos=n%(a+b);
	if(pos==0){
		printf("SECOND\n");return;
	}
	if(pos<a||pos>b){
		printf("DRAW\n");return;
	}
	printf("FIRST\n");
	printf("%d\n", x1+pos);
}
void solve2(int x1,int x2,int a,int b){
	//x1>x2
	int n=x1-x2;
	a=-a,b=-b; swap(a,b);
	if(a<=0){
		if(n<=b){
			printf("FIRST\n%d\n", x2);
		} else {
			printf("DRAW\n");
		}
		return;
	}
	int pos=n%(a+b);
	if(pos==0){
		printf("SECOND\n");return;
	}
	if(pos<a||pos>b){
		printf("DRAW\n");return;
	}
	printf("FIRST\n");
	printf("%d\n", x1-pos);
}
int main(){
	cin>>x1>>x2>>a>>b;
	if(x1<x2){
		solve1(x1,x2,a,b);
	} else {
		solve2(x1,x2,a,b);
	}
}
/*

int a,b;
int f[1000];
int main(){
	cin>>a>>b;
	f[0]=-1;
	for(int i=1;i<a;i++) f[i]=0;
	for(int i=a;i<=100;i++){
		int mn=1e9;
		for(int j=a;j<=b;j++){
			if(i-j>=0){
				mn=min(mn,f[i-j]);
			}
		}
		if(i==a) {
			printf("mn=%d\n", mn);
		}
		f[i]=-mn;
	}
	for(int i=0;i<=100;i++){
		printf("i=%d, res=%d\n", i,f[i]);
	}
}
*/