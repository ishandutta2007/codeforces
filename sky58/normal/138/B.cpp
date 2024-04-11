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
string su="0123456789";
int k1[15],k2[15];
int main()
{
	memset(k1,0,sizeof(k1));memset(k2,0,sizeof(k2));
	int ma=-1,re1,re2,i,j,n,k;
	string s,out1="",out2="";
	cin>>s;n=s.size();
	rep(i,n){k1[(s[i]-'0')]++;k2[(s[i]-'0')]++;}
	rep(i,k1[0]+1) REP(j,1,10){
		if(k1[j]<1 || k1[10-j]<1) continue;
		k1[0]-=i;k2[0]-=i;k1[j]-=1;k2[10-j]-=1;
		int t=i+1;rep(k,10) t+=min(k1[k],k2[9-k]);
		if(t>ma){ma=t;re1=i;re2=j;}
		k1[0]+=i;k2[0]+=i;k1[j]+=1;k2[10-j]+=1;
	}
	if(ma<0){
		sort(All(s));reverse(All(s));
		cout<<s<<endl;cout<<s<<endl;
		return 0;
	}
	rep(i,re1){
		k1[0]--;k2[0]--;out1+="0";out2+="0";
	}
	out1+=su[re2];out2+=su[10-re2];k1[re2]--;k2[10-re2]--;
	rep(j,10){
		int t=min(k1[j],k2[9-j]);
		rep(i,t){
			out1+=su[j];out2+=su[9-j];k1[j]--;k2[9-j]--;
		}
	}
	rep(i,10){
		rep(j,k1[i]) out1+=su[i];
		rep(j,k2[i]) out2+=su[i];
	}
	reverse(All(out1));reverse(All(out2));
	cout<<out1<<endl;cout<<out2<<endl;
	return 0;
}