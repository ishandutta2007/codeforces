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

string ans="NO";
map<vector<string>,int>w;
vector<string>a;
int n;

void rec(vector<string>a){
	if (w[a])return;
	w[a]=1;
	int x=a.size();
	if (x==1)ans="YES";
	if (x>1&&(a[x-1][0]==a[x-2][0]||a[x-1][1]==a[x-2][1])){
		vector<string>b=a;
		b[x-2]=b[x-1];
		b.erase(b.end()-1);
		rec(b);
	}
	if (x>3&&(a[x-1][0]==a[x-4][0]||a[x-1][1]==a[x-4][1])){
		vector<string>b=a;
		b[x-4]=b[x-1];
		b.erase(b.end()-1);
		rec(b);
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	a.resize(n);
	for (int i=0;i<n;i++)cin >> a[i];
	rec(a);
	CC(ans);
	return 0;
}