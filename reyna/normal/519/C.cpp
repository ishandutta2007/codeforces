//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%d",&a)
#define Put(a) printf("%d\n",a);
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Maxn = 1e6 + 1e3;

int main(){
	int n,m;
	cin >> n >> m;
	cout << min(n,min(m,(n + m)/3)) << endl;
	return 0;
}