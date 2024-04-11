#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , m , sum = 0 , a[100000];
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>a[i];
		sum += a[i];
		if(a[i] + i > n){
			cout<<-1<<endl;
			return 0;
		}
	}
	if(sum < n){
		cout<<-1<<endl;
		return 0;
	}
	ll x = 1;
	for(int i = 0 ; i < m ; i++){
		cout<<x<<" ";
		x += a[i];
		x -= min(sum - n , a[i] - 1);
		sum -= min(sum - n , a[i] - 1);
	}
	return 0;
}