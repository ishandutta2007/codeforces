#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int a[10][10];

int main(){
///	freopen("in.txt", "r", stdin);
	for(int i = 0; i < 4; i ++){
		for(int j = 1; j <= 4; j ++) scanf("%d", a[i] + j);
	}

	for(int i = 0; i < 4; i ++){
		if(a[i][1]){
			int lef = (i + 3) % 4;
			if(a[lef][4] || a[i][4]){ puts("YES"); return 0; }
		}
		if(a[i][3]){
			int rig = (i + 1) % 4;
			if(a[rig][4] || a[i][4]){ puts("YES"); return 0; }
		}
		if(a[i][2]){
			int cet = (i + 2) % 4;
			if(a[cet][4] || a[i][4]){ puts("YES"); return 0; }
		}
	}
	puts("NO"); return 0;
}