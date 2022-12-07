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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,m,x,y,a[1111][1111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		a[x][y]=1;
		for (int ii=0;ii<3;ii++)for (int jj=0;jj<3;jj++)if (x-ii>=0&&y-jj>=0&&x-ii+3<=n&&y-jj+3<=n){
			int t=0;
			for (int xx=0;xx<3;xx++)for (int yy=0;yy<3;yy++)if (!a[x-ii+xx][y-jj+yy])t=1;
			if (!t){
				CC(i+1);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}