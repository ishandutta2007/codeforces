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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

string s;
char ans[11111];
int a[33],l,o=0;
vt e;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s;
	for (int i=0;i<s.size();i++)a[s[i]-'a']++;
	for (int i=0;i<26;i++)if (a[i]>o)o=a[i],l=i;
	for (int i=2;i<=s.size();i++){
		int t=0;
		for (int j=2;j<i;j++)if (i%j==0)t=1;
		if (t==0&&i*2<=s.size())e.pb(i);
	}	
	for (int i=0;i<s.size();i++){
		int t=0;
		for (int j=0;j<e.size();j++)if ((i+1)%e[j]==0)t=1;
		if (t){
			if (!a[l]){
				puts("NO");
				return 0;
			}
			ans[i]=l+'a';
			a[l]--;
		}
	}
	for (int i=0;i<s.size();i++)if (!ans[i])for (int j=0;j<26;j++)if (a[j]){
		ans[i]=j+'a';
		a[j]--;
		break;
	}
	puts("YES");
	puts(ans);
	return 0;
}