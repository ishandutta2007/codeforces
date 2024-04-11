#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int n,x[5555],y[5555],z[5555];
long double ans=999999999;

long double R(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
}

int main(void){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]);			
	for (int i=1;i<n;i++)for (int j=i+1;j<n;j++){
		ans=min(ans,(R(i,j)+R(0,i)+R(0,j))/2);
	}
	cout.precision(8);
	cout << fixed << ans << endl;
	return 0;
}