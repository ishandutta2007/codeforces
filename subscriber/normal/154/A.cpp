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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

char a[111111];
int nn,e,p,ans=0,n,aa,bb;
string s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	nn=strlen(a);
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s;
		aa=0;
		bb=0;
		for (int j=0;j<nn;j++){
			if (a[j]!=s[0]&&a[j]!=s[1]){
				ans+=min(aa,bb);
				aa=0;
				bb=0;
			}
			if (a[j]==s[0])aa++;
			if (a[j]==s[1])bb++;
		}
		ans+=min(aa,bb);
	}
	CC(ans);
	return 0;
}