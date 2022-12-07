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

int n,p[111111],k,x,d;
long long v[111111];
long long ans;      

void gg(int x){
	int y=x;
	long long s=0;
	while (p[x]!=x)s+=v[x],x=p[x];
	while (x!=y){
		int t=p[y],d=v[y];
		v[y]=(s%M+M*1ll*M)%M;
		s-=d;
		p[y]=x;
		y=t;
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)p[i]=i;
	for (int i=0;i<n;i++){
		cin >> k;
		for (int j=0;j<k;j++){
			cin >> x >> d;
			x--;
			gg(x);
			ans+=v[x]+d;
			v[p[x]]=(v[x]+d+M*1ll*M)%M;
			p[p[x]]=i;
		}
	}
	ans+=M*1ll*M;
	ans%=M;
	CC(ans);
	return 0;
}