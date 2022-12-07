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

int P,k,n;
string vo,ty,s;
map<string,string>ma;
vector<string>e[1111],ee;
char a[1111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> P;
	for (int i=0;i<P;i++){
		cin >> vo;
		gets(a);
		n=strlen(a);
		s="";
		for (int j=0;j<n;j++){
			if (a[j]=='('||a[j]==','||a[j]==')'&&s.size())e[i].pb(s),s="";
			if (a[j]>='0'&&a[j]<='9'||a[j]>='a'&&a[j]<='z'||a[j]=='T')s+=a[j];
		}
	}
	cin >> k;
	for (int i=0;i<k;i++){
		cin >> vo >> ty;
		ma[ty]=vo;
	}
	scanf("%d\n",&k);
	for (int i=0;i<k;i++){
		gets(a);
		n=strlen(a);
		s="";
		ee.clear();
		for (int j=0;j<n;j++){
			if (a[j]=='('||a[j]==','||a[j]==')'&&s.size())ee.pb(s),s="";
			if (a[j]>='0'&&a[j]<='9'||a[j]>='a'&&a[j]<='z')s+=a[j];
		}
		for (int j=1;j<ee.size();j++)ee[j]=ma[ee[j]];
		int ans=0;
		for (int j=0;j<P;j++)if (e[j][0]==ee[0]&&e[j].size()==ee.size()){
			int t=0;
			for (int l=1;l<ee.size();l++)if (e[j][l]!="T"&&e[j][l]!=ee[l])t=1;
			if (!t)ans++;
		}
		CC(ans);
	}
	return 0;
}