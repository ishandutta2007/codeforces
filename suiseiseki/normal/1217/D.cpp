#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 5000
#define Mod 998244353
int n,m;
pair<int,int> a[Maxn+5];
vector<int> v[Maxn+5];
bool f[Maxn+5];
int d[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	bool flag=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
		v[a[i].first].push_back(a[i].second);
		d[a[i].second]++;
	}
	for(int i=1;i<=n;i++){
		int mn=0;
		for(int j=1;j<=n;j++){
			if(d[j]==0&&f[j]==0){
				mn=j;
			}
		}
		f[mn]=1;
		if(mn==0){
			flag=1;
			break;
		}
		for(int j=0;j<(int)v[mn].size();j++){
			d[v[mn][j]]--;
		}
	}
	if(!flag){
		puts("1");
		for(int i=1;i<=m;i++){
			printf("1 ");
		}
	}
	else{
		puts("2");
		for(int i=1;i<=m;i++){
			if(a[i].first<a[i].second){
				printf("1 ");
			}
			else{
				printf("2 ");
			}
		}
	}
	return 0;
}