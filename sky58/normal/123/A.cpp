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
bool aru[1100];
int ka[30];
int main()
{
	string s;cin>>s;int it=0,t=0,n=s.size(),i,j,ma=0,mai;
	rep(i,n) ka[(s[i]-'a')]++;
	rep(i,26){
		if(ma<ka[i]){mai=i;ma=ka[i];}
	}
	memset(aru,false,sizeof(aru));
	REP(i,2,n+1){
		if(aru[i] || n/2<i) continue;
		for(j=i;j<=n;j+=i){
			if(!aru[j]) t++;aru[j]=true;
		}
	}
//	cout<<t<<' '<<ma<<' '<<mai<<endl;
	if(t>ma){cout<<"NO"<<endl;return 0;}
	ka[mai]-=t;
	rep(i,n){
		if(aru[i+1]) s[i]=('a'+mai);
		else{
			while(ka[it]<1) it++;s[i]=('a'+it);ka[it]--;
		}
	}
	cout<<"YES"<<endl;cout<<s<<endl;return 0;
}