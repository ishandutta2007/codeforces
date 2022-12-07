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
int num[364364];
bool read[364364];
vector<int> unr;
queue<int> ea[364364];
int main()
{
	int n,q,all=0,nr=0,t,x,qn=0;
	scanf("%d %d",&n,&q);
	memset(num,0,sizeof(num));
	memset(read,false,sizeof(read));
	rep(i,q){
		scanf("%d %d",&t,&x);
		if(t==1){
			x--;
			unr.pb(x);
			num[x]++;
			all++;
			ea[x].push(qn);qn++;
		}
		if(t==2){
			x--;
			all-=num[x];
			num[x]=0;
			while(ea[x].size()){
				read[ea[x].front()]=true;ea[x].pop();
			}
		}
		if(t==3){
			REP(j,nr,x){
				if(j>=(int)unr.size()) continue;
				int y=unr[j];
				if(num[y]>0 && !read[j]) num[y]--,all--;
			}
			nr=max(nr,x);
		}
		printf("%d\n",all);
	}
}