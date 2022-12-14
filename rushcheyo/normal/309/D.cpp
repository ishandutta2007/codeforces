#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m,n++;
	long long ans=0;
	for(int a=m+1;a<=n/2;a++){
		int tmp=0;
		for(int b=m+1,c=m+1;b<n-m&&c<n-m;b++){
			while(c<n-m&&a*(2*a+b+c-3*n)>=c*(n+b)-n*n-n*b)c++;
			tmp+=n-m-c;
		}
		if(a!=n-a)tmp*=2;
		ans+=tmp;
	}
	cout<<ans*3<<endl;
	return 0;
}