#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;

int n,a,b,c,ans;

int main(void){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> a >> b >> c;
	for (int i=0;i<=c;i++)for (int j=0;j<=b;j++){
		int x=n-(2*i)-j;
		if (x>=0&&x*2<=a)ans++;
	}			
	cout << ans << endl;

	return 0;
}