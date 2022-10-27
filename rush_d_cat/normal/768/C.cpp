#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n,k,x,c[1050];
void Trans() {
	int d[1050]={0};
	int fg = 0;
	for(int i=0;i<1024;i++){
		int tmp = (fg==0) ? (c[i]+1)/2 : c[i]/2;
		fg ^= (c[i]%2);
		d[x ^ i] += tmp;
		d[i] += c[i] - tmp; 
	}
	for(int i=0;i<1024;i++) c[i]=d[i];
}
int main() {
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1;i<=n;i++){
		int t; scanf("%d",&t); c[t]++;
	}
	for(int i=1;i<=k;i++) Trans();
	for(int i=1023;i>=0;i--)if(c[i]){
		printf("%d ", i);break;	
	}
	for(int i=0;i<1024;i++)if(c[i]){
		printf("%d ", i);break;
	}
}