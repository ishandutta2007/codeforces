#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef double ld;
typedef pair<int,int> pi;
int n;
ld p[1000];
const int cc=2;
ld a[201][cc*101][cc*101];
ld get(int IT){
	for (int it=0;it<=IT;it++)
		for (int i=0;i<=cc*n;i++)
			for (int j=0;j<=cc*n;j++)
				a[it][i][j]=-100;
	for (int i=0;i<=cc*n;i++)
		for (int j=0;j<=min(n,i);j++)
			a[0][i][min(cc*n,i-j+n-j)]=max(a[0][i][min(cc*n,i-j+n-j)],p[j]);
	for (int it=1;it<=IT;it++){
		for (int i=0;i<=cc*n;i++)
			for (int j=0;j<=cc*n;j++)
				for (int k=0;k<=cc*n;k++)
					a[it][i][k]=max(a[it][i][k],(a[it-1][i][j]+a[it-1][j][k])/2);
	}
	ld ans=0;
	for (int i=0;i<=cc*n;i++)
    	ans=max(ans,a[IT][0][i]);
    return ans;
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	for (int i=0;i<=n;i++){
		cin>>p[i];
	}
	printf("%.18lf\n",(double)get(30));
	return 0;
}