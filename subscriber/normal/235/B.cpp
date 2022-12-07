#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n;
double p[311111],f[311111],ans;

int main(){
//	freopen("input.txt","r",stdin);	
//	freopen("output.txt","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> p[i];
	f[0]=0;
	for (int i=0;i<n;i++){
		f[i]=(f[i-1]+1)*p[i];
	}
	for (int i=0;i<n;i++)ans+=f[i]*2-p[i];
	printf("%.8lf\n",ans);
	return 0;
}