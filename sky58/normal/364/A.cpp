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
int sum[4010];
int num[40010];
int main()
{
	int a;string s;
	cin>>a;cin>>s;
	int n=s.size();lint ret=0;
	memset(sum,0,sizeof(sum));memset(num,0,sizeof(num));
	rep(i,n) sum[i+1]=sum[i]+(s[i]-'0');
	rep(i,n) REP(j,i+1,n+1) num[sum[j]-sum[i]]++;
	rep(i,n) REP(j,i+1,n+1){
		int t=sum[j]-sum[i];
		if(t==0){
			if(a==0) ret+=(n+1)*n/2;continue;
		}
		if(a%t==0 && a/t<40005) ret+=num[a/t];
	}
	cout<<ret<<endl;
	return 0;
}