#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
 
const int MAX_N = 1e5 + 20;
 
int tav(int n , int k){
	int res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , h;
	cin>>n;
	h = n / 3;
	h *= 2;
	n %= 3;
	if(n) h++;
	cout<<h<<'\n';
	return 0;
}