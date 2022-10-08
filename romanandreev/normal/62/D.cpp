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
vector<int> v[3000];
int bd[1000][1000];
int w[1000][1000];
int a[3000];
int aa[3000];
int cnt;
int n,m,f;
bool dfs(int vv,int k){
	if (vv==a[0] && k==m+1) return true;
	int e;
	for (int i=0;i<(int)v[vv].size();i++){
		e=v[vv][i];
		if (bd[vv][e]!=cnt){
			bd[vv][e]=cnt;
			bd[e][vv]=cnt;
			aa[k]=e;
			if (dfs(e,k+1)){
				return true;
			}
			bd[vv][e]=cnt-1;
			bd[e][vv]=cnt-1;
		}
	}
	return false;
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[0]);
	for (int i=0;i<m;i++){
		scanf("%d",&a[i+1]);
		w[a[i]][a[i+1]]=i+1;
		w[a[i+1]][a[i]]=i+1;
		v[a[i]].pb(a[i+1]);
		v[a[i+1]].pb(a[i]);
	}
	for (int i=0;i<=n;i++){
		sort(v[i].begin(),v[i].end());
	}
	cnt=0;
	for (int i=m-1;i>=1;i--){
		for (int nx=a[i]+1;nx<=n;nx++) if (w[a[i-1]][nx]>=i){
			cnt++;
			aa[0]=a[0];
			for (int j=1;j<=i-1;j++){
				aa[j]=a[j];
				bd[a[j-1]][a[j]]=cnt;
				bd[a[j]][a[j-1]]=cnt;
			}
			aa[i]=nx;
			bd[a[i-1]][nx]=cnt;
			bd[nx][a[i-1]]=cnt;
			if (dfs(nx,i+1)){
				for (int i=0;i<=m;i++){
					cout<<aa[i]<<" ";
				}
				cout<<endl;
				return 0;
			}
		}
	}
	cout<<"No solution"<<endl;
    return 0;
}