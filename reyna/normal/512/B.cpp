//In the name of God
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int Maxn = 305;
const long long oo = (long long)1 << 60;
int arr[Maxn];
long long c[Maxn];
map<int,long long> ans;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++)
		cin >> arr[i];
	for(int i = 0; i < n;i++)
		cin >> c[i];
	int tmp = arr[0];
	for(int i = 0;i < n;i++){
		tmp = gcd(max(tmp,arr[i]),min(tmp,arr[i]));
	}
	if(tmp != 1){
		cout << -1 << endl;
		return 0;
	}
	long long Ans = oo;
	ans[arr[0]] = c[0];
	for(int i = 1; i < n;i++){
		if(ans[arr[i]]){
			ans[arr[i]] = min(c[i],ans[arr[i]]);
		}else{
			ans[arr[i]] = c[i];
		}
		for(map<int, long long> :: iterator it = ans.begin();it != ans.end();++it){
			pair<int,long long> now = *it;
			if(ans[gcd(now.first,arr[i])])
				ans[gcd(now.first,arr[i])] = min(ans[gcd(now.first,arr[i])],now.second+c[i]);
			else
				ans[gcd(now.first,arr[i])] = now.second+c[i];
		}
	}
	if(ans[1] == 0){
		cout << -1 << endl;
		return 0;
	}
	cout << ans[1] << endl;
	return 0;
}