//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 1e6 + 9;
long long d[Maxn];
long long sum = 0;
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	long long A;
	cin >> n >> A;
	For(i,0,n)
		cin >> d[i],sum += d[i];
	For(i,0,n){
		cout << min(max((long long)0,(A - (sum - d[i])) - 1) + max((long long)0,d[i] - (A - (n - 1))),d[i]) << ' ';
	}
	return 0;
}