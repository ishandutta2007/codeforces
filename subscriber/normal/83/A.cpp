#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,a[111111],u;
long long ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++){
		if (!i)u=0;else	if (a[i]!=a[i-1])u=i;
		ans+=(i-u+1);
	}
	cout << ans << endl;
	return 0;
}