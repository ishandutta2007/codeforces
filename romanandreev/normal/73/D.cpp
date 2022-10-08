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
int head[2001000];
int next[2001000];
int e[2001000];
int b[2001000];
int cv[2001000];
int n,m,k,cnt,x,y;
int kl=0;
void add(int x,int y){
	kl++;
	next[kl]=head[x];
	head[x]=kl;
	e[kl]=y;
}
void dfs(int v){
	b[v]=1;
	cv[cnt]++;
	for (int bb=head[v];bb;bb=next[bb]){
		if (b[e[bb]]==0)
			dfs(e[bb]);
	}
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		add(x,y);
		add(y,x);
	}
	cnt=0;
	for (int i=0;i<n;i++){
		if (b[i]==0){			
			dfs(i);
			cnt++;
		}
	}
	if (k==1){
		cout<<max(0,cnt-2)<<endl;
		return 0;
	}
	int sum=0;
	int cc=0;
	int ans=0;
	for (int i=0;i<cnt;i++) 
		if (cv[i]==1){
			cc++;
		} else {
			sum+=min(k,cv[i])-2;
		}
//	cerr<<cc<<" "<<cnt<<" "<<sum<<endl;
	if (cc==cnt){
		if (cc==1) {
			cout<<0<<endl;
			return 0;
		}
		if (cc==2) {
			cout<<0<<endl;
			return 0;
		}
		cc-=2;
		cnt--;
		ans++;
	}
	cc=max(0,cc-2);
	if (sum>=cc){
		cout<<ans<<endl;
		return 0;
	}
	cout<<(cc-sum+1)/2+ans<<endl;
    return 0;
}