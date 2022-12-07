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

int n,m,p[1111],u[1111],a,b;
double q[1111][1111],t[1111][1111],ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)cin >> p[i],u[p[i]-1]=i;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)if (p[i]<p[j])q[i][j]=1;
	for (int g=0;g<m;g++){
		cin >> a >> b;
		a--;
		b--;
		for (int i=0;i<n;i++)t[a][i]=t[i][a]=t[i][b]=t[b][i]=0;
		for (int i=0;i<n;i++)if (i!=a&&i!=b){
			t[i][b]+=q[i][a]/2;
			q[i][a]/=2;
			t[i][a]+=q[i][b]/2;
			q[i][b]/=2;
			t[b][i]+=q[a][i]/2;
			q[a][i]/=2;
			q[a][i]+=q[b][i]/2;
			q[b][i]/=2;
		}
		t[a][b]+=q[b][a]/2;
		q[b][a]/=2;
		t[b][a]+=q[a][b]/2;
		q[a][b]/=2;
		for (int i=0;i<n;i++){
			q[i][a]+=t[i][a];
			t[i][a]=0;
			q[i][b]+=t[i][b];
			t[i][b]=0;
			q[a][i]+=t[a][i];
			t[a][i]=0;
			q[b][i]+=t[b][i];
			t[b][i]=0;
		}
	}
	for (int i=0;i<n;i++)for (int j=i+1;j<n;j++)ans+=q[j][i];
	printf("%.10lf\n",ans);
	return 0;
}