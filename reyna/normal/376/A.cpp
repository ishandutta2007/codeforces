//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%I64d",&a)
#define Put(a) printf("%I64d\n",a)
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Maxn = 1e6 + 1e3;
int main(){
	string S;
	cin >> S;
	int n = S.size();
	ll cnt = 0;
	int root = 0;
	ll left = 0;
	ll right = 0;
	For(i,0,n){
		if(S[i] == '^'){
			root = i;
			For(j,0,root){
				if(S[j] != '=')
					left += (S[j] - '0') * cnt;
				cnt--;
			}
			For(j,root+1,n){
				cnt++;
				if(S[j] != '=')
					right += (S[j] - '0') * cnt;
			}
		}
		cnt++;
	}
	if(left == right){
		cout << "balance" << endl;
	}
	if(left > right){
		cout << "left" << endl;
	}
	if(right > left){
		cout << "right" << endl;
	}
	return 0;
}