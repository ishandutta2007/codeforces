#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 200000
#define ll long long
int a[Maxn+5];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int maxn_1=(-1<<30),maxn_2=(-1<<30);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>maxn_1){
			maxn_2=maxn_1;
			maxn_1=a[i];
		}
		else if(a[i]>maxn_2){
			maxn_2=a[i];
		}
	}
	if(m<=k){
		cout<<(ll)maxn_1*m<<endl;
	}
	else{
		cout<<(ll)maxn_1*(m-m/(k+1))+(ll)maxn_2*(m/(k+1))<<endl;
	}
	return 0;
}