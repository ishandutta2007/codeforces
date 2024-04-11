#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int zyo[10];int aru[110000][10];
bool so[110000];
int hyo[6][4][4]={{{}},{{}},{{7}},{{7,0},{0,7}},{{7,2,1},{2,7,0},{1,0,7}},{{7,5,4,2},{5,7,3,1},{4,3,7,0},{2,1,0,7}}};
int cal(int a,int b){return (a%zyo[b+1])/zyo[b];}
int main()
{
	int i,j,k,l,n,t,x;string st;
	memset(aru,0,sizeof(aru));memset(so,false,sizeof(so));
	so[0]=so[1]=true;
	zyo[0]=1;rep(i,9) zyo[i+1]=zyo[i]*10;
	REP(i,2,100000){
		if(so[i]) continue;
		rep(j,5) aru[i/zyo[j+1]*zyo[j+1]+i%zyo[j]][j]++;
		for(j=i+i;j<100000;j+=i) so[j]=true;
	}
//	cout<<aru[10][0]<<endl;
	cin>>t;
	rep(i,t){
		cin>>st;istringstream sin(st);sin>>x;
		int out=0,n=st.size();
		rep(j,zyo[(n-2)*(n-1)/2]){
			int ret=1;
			for(k=n-2;k>=0 && ret>0;k--){
				int s=cal(x,k)*zyo[n-1];
				rep(l,n-1){
					if(k==l) continue;s+=zyo[l]*cal(j,hyo[n][k][l]);
				}
				ret*=aru[s][k];
			}
			out+=ret;
		}
		cout<<out<<endl;
	}
	return 0;
}