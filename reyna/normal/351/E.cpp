//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2005;
pair<int,int> sr[Maxn];
int arr[Maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i],arr[i] = abs(arr[i]),sr[i] = make_pair(abs(arr[i]),i);
	sort(sr,sr+n);
	reverse(sr,sr+n);
	int ans = 0;
	for(int i = 0; i < n;i++){
		int id = sr[i].second;
		int x1 = 0,x2 = 0;
		for(int j = 0; j < id;j++){
			if(arr[id] > arr[j]) x1++;
		}
		for(int j = id + 1; j < n;j++){
			if(arr[id] > arr[j]) x2++;
		}
		ans += min(x1,x2);
	}
	cout << ans << endl;
	return 0;
}