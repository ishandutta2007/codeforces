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
string mat[8];
map<char,int> val;
int main(){
	int n = 8;
	int cnt = 0;
	val['q'] = 9,val['Q'] = -9;
	val['r'] = 5,val['R'] = -5;
	val['b'] = 3,val['B'] = -3;
	val['n'] = 3,val['N'] = -3;
	val['p'] = 1,val['P'] = -1;
	
	For(i,0,n){
		cin >> mat[i];
		For(j,0,n){
			cnt += val[mat[i][j]];
		}
	}
	if(cnt < 0){
		cout << "White" << endl;
	}else if(cnt > 0){
		cout << "Black" << endl;
	}else{
		cout << "Draw" << endl;
	}
}