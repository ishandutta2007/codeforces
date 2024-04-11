#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

ll r[MAX_N];

int main(){
	ll n;
	cin>>n;
	r[0] = 0;
	for(int i = 1 ; i < MAX_N ; i++){
		r[i] = r[i - 1] + i;
	}
	if(n < 0) n = 0 - n;
	for(int i = 0 ; i < MAX_N ; i++){
		if(r[i] >= n && r[i] % 2 == n % 2){
			cout<<i<<"\n";
			return 0;
		}
	}
}