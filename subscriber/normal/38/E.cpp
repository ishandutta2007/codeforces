#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <time.h>

using namespace std;

struct T{long long x,c;} q[3111];

bool my(T A,T B){
	return A.x<B.x;
}

int n;
long long f[3011][3011],ans;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)cin >> q[i].x >> q[i].c;
	sort(q,q+n,&my);
	memset(f,63,sizeof(f));
	ans=f[0][0];
	f[0][0]=q[0].c;
	for (int i=0;i<n-1;i++)for (int j=0;j<=i;j++){
		f[i+1][i+1]=min(f[i+1][i+1],f[i][j]+q[i+1].c);
		f[i+1][j]=min(f[i+1][j],f[i][j]+q[i+1].x-q[j].x);
	}
	for (int i=0;i<n;i++)ans=min(ans,f[n-1][i]);
	cout << ans << endl;
	return 0;
}