#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n , a , b , d[100001] , e[100000][2] , m = -1;
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		d[i] = 0;
	}
	for(int i = 1 ; i < n ; i++){
		cin>>a>>b;
		d[a]++;
		d[b]++;
		e[i][0] = a;
		e[i][1] = b;
	}
	for(int i = 1 ; i <= n ; i++){
		if(d[i] >= 3){
			m = i;
			break;
		}
	}
	if(m == -1){
		for(int i = 0 ; i < n - 1 ; i++){
			cout<<i<<endl;
		}
		return 0;
	}
	ll y = 0 , u = 3;
	for(int i = 1 ; i < n ; i++){
		if((e[i][0] == m || e[i][1] == m) && y != 3){
			cout<<y<<endl;
			y++;
		} else {
			cout<<u<<endl;
			u++;
		}
	}
	return 0;
}