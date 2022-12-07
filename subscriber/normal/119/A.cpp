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


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	int a,b,n;
	cin >> a >> b >> n;
	for (int o=0;;o^=1){
		if (!o){
			if (n<__gcd(a,n)){
				puts("1");
				return 0;
			}
			n-=__gcd(a,n);
		}else{
			if (n<__gcd(b,n)){
				puts("0");
				return 0;
			}
			n-=__gcd(b,n);
		}
	}
	return 0;
}