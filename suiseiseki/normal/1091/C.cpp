#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
ll f[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	int len=0;
	int x;
	ll num;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			x=n/i;
			num=(ll)x*(x-1)*i;
			num>>=1;
			num+=x;
			f[++len]=num;
			if(i*i!=n){
				x=n/(n/i);
				num=(ll)x*(x-1)*(n/i);
				num>>=1;
				num+=x;
				f[++len]=num;
			}
		}
	}
	sort(f+1,f+1+len);
	for(int i=1;i<=len;i++){
		cout<<f[i]<<" ";
	}
	puts("");
	return 0;
}