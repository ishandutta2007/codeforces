#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
const int N=25;
int n,k,c;
double p[N],f[1<<20],ans[N],s[1<<20];

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>p[i],c+=p[i]>eps;
	k=min(k,c);
	f[0]=1;
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++)
			if(i&(1<<j)) s[i]+=p[j];
		for(int j=0;j<n;j++)
			if(i&(1<<j)) f[i]+=f[i^(1<<j)]*p[j]/(1.0-s[i^(1<<j)]);
	}
	for(int i=1;i<(1<<n);i++)
		if(__builtin_popcount(i)==k)
			for(int j=0;j<n;j++)
				if(i&(1<<j)) ans[j]+=f[i];
	for(int i=0;i<n;i++) printf("%.12f ",ans[i]);puts("");
	return 0;
}