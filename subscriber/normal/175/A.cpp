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

int n,x1,x2,x3,ans=-1;
string s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s;
	n=s.size();
	for (int i=0;i<n-1;i++)for (int j=0;j<i;j++){
		string s1="",s2="",s3="";
		for (int l=0;l<=j;l++)s1+=s[l];
		for (int l=j+1;l<=i;l++)s2+=s[l];
		for (int l=i+1;l<n;l++)s3+=s[l];
		if (s1.size()>8||s2.size()>8||s3.size()>8)continue;
		if (s1.size()>1&&s1[0]=='0')continue;
		if (s2.size()>1&&s2[0]=='0')continue;
		if (s3.size()>1&&s3[0]=='0')continue;
		SS q1,q2,q3;
		q1<<s1;
		q2<<s2;
		q3<<s3;
		q1>>x1;
		q2>>x2;
		q3>>x3;
		if (x1>1000000||x2>1000000||x3>1000000)continue;
		ans=max(ans,x1+x2+x3);
	}
	CC(ans);
	return 0;
}