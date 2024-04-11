#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int n,m,k,ans;
char a[100][100][100];
int w[100][100][100];
void dfs(int x,int y,int z){
	if (x<0 || x>=n) return;
	if (y<0 || y>=m) return;
	if (z<0 || z>=k) return;
	if (w[x][y][z]==1) return;
	if (a[x][y][z]=='#') return;
	w[x][y][z]=1;
	ans++;
	dfs(x+1,y,z);
	dfs(x-1,y,z);
	dfs(x,y+1,z);
	dfs(x,y-1,z);
	dfs(x,y,z+1);
	dfs(x,y,z-1);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			scanf("%s",a[i][j]);
		}	
	}
	int x,y;
	cin>>x>>y;
	x--;
	y--;
	ans=0;
	dfs(0,x,y);
	cout<<ans;
    return 0;
}