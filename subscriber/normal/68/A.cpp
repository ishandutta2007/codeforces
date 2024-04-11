#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

int p[4],a,b,ans=0,e[4];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
	for (int i=a;i<=b;i++){
		for (int j=0;j<4;j++)e[j]=j;
		int t=0;
		for(;;){
			int u=i;
			for (int j=0;j<4;j++)u%=p[e[j]];
			t+=u==i;
			if (!next_permutation(e,e+4))break;
		}
		ans+=t>6;
	}
	cout << ans << endl;
	return 0;
}