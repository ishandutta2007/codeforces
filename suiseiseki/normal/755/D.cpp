#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 1000000
#define ll long long
ll d[Maxn+5];
ll b[Maxn+5];
ll c[Maxn+5];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>(n>>1)){
		k=n-k;
	}
	d[0]=b[0]=1;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+k;
		c[i]=(b[i]-1)/n;
	}
	bool flag=0;
	int t=0;
	for(int i=1;i<=n;i++){
		if(c[i]==c[i-1]){
			if(!flag){
				flag=1;
				t++;
			}
		}
		else{
			if(flag){
				flag=0;
			}
			t++;
		}
		d[i]=d[i-1]+t;
	}
	for(int i=1;i<n;i++){
		cout<<d[i]<<' ';
	}
	cout<<(ll)n*k+1<<endl;
	return 0;
}