#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;


int main(){
	int n,x[2],y[2];
	scanf("%d%d%d%d%d",&n,&x[0],&y[0],&x[1],&y[1]);
	
	rep(i,2){
		if (y[i] == n){
			x[i] = 3*n-x[i];
		} else {
			if (x[i] == n){
				x[i] = n+y[i];
			} else {
				if (x[i] == 0) x[i] = 4*n-y[i];
			}
		}
	}
	
	if (x[0] < x[1]) x[0] = x[1]-x[0]; else x[0] = x[0]-x[1];
	
	printf("%d\n",min(x[0],4*n-x[0]));
	
	return 0;
}