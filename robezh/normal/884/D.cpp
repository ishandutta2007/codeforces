#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > pque;

int main(){
	int n;
	long long sum = 0;
	int tmp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		pque.push(tmp);
	}
	if(pque.size() % 2 == 0) pque.push(0);
	while(pque.size() > 1){
		ll psum = pque.top(); pque.pop();
		psum += pque.top(); pque.pop();
		psum += pque.top(); pque.pop();
		pque.push(psum);
		sum += psum;
	}
	cout<<sum;
	
}