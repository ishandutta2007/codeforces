//In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 1e5 + 1e3;
pair<int,int> arr[Maxn];
int b[Maxn];
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first < b.first)
		return 1;
	if(a.first == b.first && a.first > b.first)
		return 1;
	return 0;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr,arr+n,cmp);
	for(int i = 0; i < n;i++){
		b[i] = arr[i].second;
	}
	int Max = 0;
	int ans = 0;
	for(int i = 0; i < n;i++){
		if(Max > b[i]){
			ans++;
		}
		Max = max(b[i],Max);
	}
	cout << ans << endl;
	return 0;
}