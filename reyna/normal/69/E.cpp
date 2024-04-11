//In the name of God
#include <iostream>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
const int Maxn = 1e5 + 9;
int arr[Maxn];
set<pair<int,int> > st;
map<int,int> mp;
void add(int x){
	st.erase(make_pair(mp[x]++,-x));
	st.insert(make_pair(mp[x],-x));
	return;
}
void del(int x){
	st.erase(make_pair(mp[x]--,-x));
	if(mp[x])
		st.insert(make_pair(mp[x],-x));
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n;i++)
		cin >> arr[i];
	for(int i = 0; i < k-1;i++){
		add(arr[i]);
	}
	for(int i = 0; i < n-k+1;i++){
		int to_add = i + k - 1;
		int to_del = i;
		add(arr[to_add]);
		pair<int,int> cur = *(st.begin());
		if(cur.first == 1)
			cout << -cur.second << "\n";
		else
			cout << "Nothing\n";
		del(arr[to_del]);
	}
	return 0;
}