#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int Q;
ll N;
vector<ll> v;
vector<ll> ans;

ll gcd(ll a, ll b){
	//cout<<a<<' '<<b<<endl;
	if(b==0)	return a;
	return gcd(b, a%b);
}

int arr[100] = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main(){
	scanf("%d", &Q);
	ll two = 4;
	while(two<=(1<<25)){
		ll now = two-1;
		//cout<<now<<endl;
		v.push_back(now);
		ans.push_back(arr[v.size()-1]);
		two*=2;
	}
	while(Q--){
		scanf("%lld", &N);
		bool tf = false;
		ll p = 0;
		for(int i=0; i<v.size(); i++){
			if(N<v[i]){
				p = v[i];
				break;
			}
			if(N==v[i]){
				printf("%lld\n", ans[i]);
				tf = true;
			}
		}
		if(!tf){
			printf("%lld\n", p);
		}
	}
	return 0;
}