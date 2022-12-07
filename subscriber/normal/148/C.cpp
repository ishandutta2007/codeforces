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

int n,a,b,s,p=1;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> a >> b;
	if (b==0&&a&&a+b+1==n){
		puts("-1");
		return 0;
	}
	if (b==0&&a){
		cout << "1 ";
		n--;
	}
	cout << "1";
	s=1;
	for (int i=0;i<b;i++)cout << " " << s+1,p=s+1,s+=s+1;
	for (int i=0;i<a;i++)cout << " " << p+i+1;	
	for (int i=0;i<n-a-b-1;i++)cout << " 1";
	return 0;
}