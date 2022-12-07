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

int a[111111],b[111111],k=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	int t=0;
	for(;;){
		string s;
		if (!(cin>>s))break;
		a[k]=-1;
		if (s.size()>3&&s.rfind("lios")==s.size()-4)a[k]=0,b[k]=0;
		if (s.size()>4&&s.rfind("liala")==s.size()-5)a[k]=0,b[k]=1;
		if (s.size()>2&&s.rfind("etr")==s.size()-3)a[k]=1,b[k]=0;
		if (s.size()>3&&s.rfind("etra")==s.size()-4)a[k]=1,b[k]=1;
		if (s.size()>5&&s.rfind("initis")==s.size()-6)a[k]=2,b[k]=0;
		if (s.size()>5&&s.rfind("inites")==s.size()-6)a[k]=2,b[k]=1;
		if (a[k]==-1){
			puts("NO");
			return 0;
		}
		if (a[k]==1)t++;
		k++;
	}
	if (k==1){
		puts("YES");
		return 0;
	}
	if (t!=1){
		puts("NO");
		return 0;
	}
	for (int i=1;i<k;i++)if (b[i]!=b[i-1]||a[i]<a[i-1]){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}