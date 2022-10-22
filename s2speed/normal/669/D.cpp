#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;

const int MAX_N = 1e6 + 20;

int ans[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , q , i = 0 , j = 1;
	cin>>n>>q;
	while(q--){
		int o;
		cin>>o;
		if(o == 2){
			if(i % 2 == 0){
				i++;
				j--;
			} else {
				i--;
				j++;
			}
		} else {
			int k;
			cin>>k;
			i += k + n; i %= n;
			j += k + n; j %= n;
		}
	}
	int o = 1;
	for(int k = 0 ; k < n / 2 ; k++){
		ans[i] = o;
		o += 2;
		i += 2; i %= n;
	}
	o = 2;
	for(int k = 0 ; k < n / 2 ; k++){
		ans[j] = o;
		o += 2;
		j += 2; j %= n;
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}