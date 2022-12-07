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

int k,b,n,a[111111],s,o;
map<int,int>w;
long long ans=0,aa;

int f(int x){
	if (x<k)return x;
	return f(x/k+x%k);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> k >> b >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	w[0]++;
	for (int i=0;i<n;i++){
		s+=a[i];
		s=f(s);
		o=s-b;
		if (o<0)o+=k-1;
		if (o==0)ans+=w[k-1];
		ans+=w[o];
		w[s]++;
	}
	s=0;
	for (int i=0;i<n;i++){
		if (a[i])s=0;else s++;
		aa+=s;
	}
	if (b==0)ans=aa;else if (b==k-1)ans-=aa;
	CC(ans);
	return 0;
}