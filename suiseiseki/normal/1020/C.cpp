#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 3000
#define ll long long
struct Peo{
	int p,c;
	friend bool operator <(Peo p,Peo q){
		return p.c<q.c;
	}
}a[Maxn+5];
bool vis[Maxn+5];
int n,m;
vector<int> b[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].p,&a[i].c);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[a[i].p].push_back(i);
	}
	for(int i=1;i<=m;i++){
		sort(b[i].begin(),b[i].end(),cmp);
	}
	ll ans=(1ll<<62);
	int num;
	ll sum;
	for(int i=0;i<=n;i++){
		sum=0;
		num=0;
		memset(vis,0,sizeof vis);
		for(int j=0;j<(int)b[1].size();j++){
			vis[b[1][j]]=1;
		}
		for(int j=2;j<=m;j++){
			if((int)b[j].size()>i){
				for(int k=(int)b[j].size()-1;k>=i;k--){
					num++;
					sum+=a[b[j][k]].c;
					vis[b[j][k]]=1;
				}
			}
		}
		int j=1;
		while((int)b[1].size()+num<=i){
			while(vis[j]){
				j++;
			}
			num++;
			sum+=a[j].c;
			vis[j]=1;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}