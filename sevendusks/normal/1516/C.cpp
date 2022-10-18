#include<iostream>
#include<cstdio>
using namespace std;
int n,a[105],s,flag;
bool f[105][200005];
int main(){
	ios::sync_with_stdio(false);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(i=2;!flag;i*=2)
		for(j=1;j<=n;j++)
			if(a[j]%i)
				flag=j;
	if(s%2)
		return cout<<0,0;
	f[0][0]=1;
	for(i=1;i<=n;i++)
		for(j=0;j<=200000;j++){
			f[i][j]=f[i-1][j];
			if(j>=a[i])
				f[i][j]|=f[i-1][j-a[i]];
		}
	if(!f[n][s/2])
		return cout<<0,0;
	cout<<1<<endl<<flag<<endl;
	return 0;
}