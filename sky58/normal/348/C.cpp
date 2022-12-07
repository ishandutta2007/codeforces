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
vector <int> num[100010],pos[100010];
lint a[100010];
int isbig[100010];
lint sum[200];//IWiv
lint sum2[200];//
int big[200];
lint cross[100010][200];
int main()
{
	int n,m,q,sq=510,numbig=0,x,y;string s;
	cin>>n>>m>>q;
	memset(isbig,-1,sizeof(isbig));
	rep(i,n) cin>>a[i];
	rep(i,m){
		cin>>x;
		if(x>sq){
			isbig[i]=numbig;big[numbig]=i;numbig++;
		}
		rep(j,x){
			cin>>y;y--;num[i].pb(y);pos[y].pb(i);if(isbig[i]>=0) sum[isbig[i]]+=a[y];
		}
	}
	//if(numbig>200) cout<<"NO"<<endl;
	rep(i,n){
		vector <int> v;
		rep(j,pos[i].size()){
			if(isbig[pos[i][j]]>=0) v.pb(isbig[pos[i][j]]);
		}
		rep(j,pos[i].size()) rep(k,v.size()) cross[pos[i][j]][v[k]]++;
	}
	rep(i,q){
		cin>>s;
		if(s=="+"){
			cin>>x>>y;x--;int t=isbig[x];
			if(t>=0) sum2[t]+=y;
			else{
				rep(j,num[x].size()) a[num[x][j]]+=y;
			}
			rep(j,numbig) sum[j]+=cross[x][j]*y;
		}
		else{
			cin>>x;x--;int t=isbig[x];
			if(t>=0) cout<<sum[t]<<endl;
			else{
				lint ret=0;
				rep(j,num[x].size()) ret+=a[num[x][j]];
				rep(j,numbig) ret+=sum2[j]*cross[x][j];
				cout<<ret<<endl;
			}
		}
	}
	return 0;
}