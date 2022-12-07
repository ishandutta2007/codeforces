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

long long a,b;

long long oo(long long x){
	if (!x)return 0;
	SS q;
	q<<x;
	string s=q.str();
	long long ans=0;
	for (int i=0;i<s.size();i++)for (char j='0';j<s[i];j++){
		if (i==0&&j=='0')continue;
		if (i==s.size()-1){
			if (s.size()==1)ans++;else if (j==s[0])ans++;
			continue;
		}
		long long w=1;
		for (int l=0;l<s.size()-i-2;l++)w*=10;
		ans+=w;
	}
	if (s[0]==s[s.size()-1])ans++;
	if (s.size()>1){
		long long g=0;
		for (int i=0;i<s.size()-1;i++)g=g*10+9;
		ans+=oo(g);
	}
	return ans;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a >> b;
	CC(oo(b)-oo(a-1));
	return 0;
}