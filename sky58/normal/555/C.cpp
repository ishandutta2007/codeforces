#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define N 262144
int dat[N*2+10][2];
int inf=1000000000;
vector<int> pos[2];
int L[N],C[N];char q[N];
int query(int a,int it){
	int ret=0;a+=N-1;
	while(a>0){
		ret=max(ret,dat[a][it]);
		a=(a-1)/2;
	}
	return max(ret,dat[0][it]);
}
//[a,b)x
void update(int a,int b,int x,int it,int k=0,int l=0,int r=N){
	if(r<=a || b<=l) return;
	if(a<=l && r<=b) dat[k][it]=max(dat[k][it],x);
	else{
		update(a,b,x,it,k*2+1,l,(l+r)/2);
		update(a,b,x,it,k*2+2,(l+r)/2,r);
		//dat[k]=max(dat[k*2+1]+add[k*2+1],dat[k*2+2]+add[k*2+2]);
	}
}
int main()
{
	memset(dat,0,sizeof(dat));
	int n,m;
	scanf("%d %d",&n,&m);
	pos[0].pb(0);pos[1].pb(0);
	rep(i,m){
		scanf("%d %d %c",&L[i],&C[i],&q[i]);
		pos[0].pb(L[i]);pos[1].pb(C[i]);
	}
	sort(All(pos[0]));pos[0].erase(unique(All(pos[0])),pos[0].end());
	sort(All(pos[1]));pos[1].erase(unique(All(pos[1])),pos[1].end());
	rep(i,m){
		//cout<<dat[N/2-1][1]<<'a'<<dat[N-1+2][1]<<endl;
		L[i]=lower_bound(All(pos[0]),L[i])-pos[0].begin();
		C[i]=lower_bound(All(pos[1]),C[i])-pos[1].begin();
		if(q[i]=='U'){
			int t=query(L[i],0);
			printf("%d\n",pos[1][C[i]]-pos[1][t]);
			update(t,C[i]+1,L[i],1);//cout<<t<<' '<<C[i]+1<<' '<<L[i]<<endl;
			update(L[i],L[i]+1,C[i],0);
		}
		else{
			int t=query(C[i],1);
			//cout<<C[i]<<' '<<t<<endl;
			printf("%d\n",pos[0][L[i]]-pos[0][t]);
			update(t,L[i]+1,C[i],0);
			update(C[i],C[i]+1,L[i],1);
		}
	}
}