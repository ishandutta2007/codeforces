#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))


int main(void){
	ll n;
	cin>>n;
	vector<int> C;
	vector<int> count;
	count.push_back(0);
	C.push_back(0);
	rep(i,n){
		count.push_back(0);
	}
	int p,c;
	rep(i,n){
		cin>>p>>c;
		C.push_back(c);
		if(p != -1 && c == 0) count[p]++;
	}
	int ans = 0;
	reps(i,n){
		if(count[i] == 0 && C[i] == 1){
			cout<<i<<" ";
			ans++;
		}
	}
	if(ans==0) cout<<-1;
	cout<<endl;
	return 0;
}