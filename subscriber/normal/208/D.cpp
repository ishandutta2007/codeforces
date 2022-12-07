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

int n;
long long p[55],ans[6],s;
pair<long long,long long>q[55];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> p[i];
	for (int i=0;i<5;i++)cin >> q[i].F,q[i].S=i;
	sort(q,q+5);
	for (int i=0;i<n;i++){
		s+=p[i];
		for (int j=4;j>=0;j--){
			ans[q[j].S]+=s/q[j].F;
			s%=q[j].F;
		}
	}
	for (int i=0;i<5;i++)cout << ans[i] << " ";
	CC("");
	CC(s);
	return 0;
}