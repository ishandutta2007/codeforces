#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

ll num[100050];
ll cat[100050];
ll res = 0;

int main(){
	int n,x,k;
	scanf("%d%d%d", &n, &x, &k);
	for(int i = 0; i < n; i++) cin >> num[i];
	sort(num, num+n);
	for(int i = 0; i < n; i++){
		//int start = num[i];
		
		ll nxt = (ll)(ceil(num[i] / (double)x)) * x;
		//cout << nxt;
		ll fst = nxt + (ll)x * (k-1);
		ll end = nxt + (ll)k * x;
		//cout << lower_bound(num, num+n, end) - lower_bound(num, num+n, fst);
		
		
		if(i != 0 && num[i] == num[i-1]) cat[i] = cat[i-1];
		else if(k == 0) cat[i] = lower_bound(num, num+n, nxt) - num - i, cat[i] = max(cat[i], (ll)0);
		else{
			cat[i] = lower_bound(num, num+n, end) - lower_bound(num, num+n, fst);
		}
	}
	for(int i = 0; i < n; i++){
		res += cat[i];
	}
	cout << res;
}