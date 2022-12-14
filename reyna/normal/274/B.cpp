#include <iostream>
#include <vector>
using namespace std;
int val[123456];
vector<int> al[123456];
bool V[123456];
int abs(int a){
	if(a <= 0){
		return a*(-1);
	}
	return a;
}
pair<long long,long long> dfs(int i){
	V[i] = true;
	long long Min = 0, Max = 0;
	for(int j = 0; j < al[i].size();j++){
		int next = al[i][j];
		if(!V[next]){
			pair<long long,long long> tmp = dfs(next);
			Min = max(tmp.first,Min);
			Max = max(tmp.second,Max);
		}
	}
	int a = val[i]-Min+Max;
	if(a <= 0){
		return make_pair(Min,Max+abs(a));
	}
	return make_pair(Min+a,Max);
		
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1;i++){
		int a,b;
		cin >> a>> b;
		a--;
		b--;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	for(int i = 0; i < n;i++)
		cin >> val[i];
	pair<long long,long long> tmp = dfs(0);
	cout << (long long)tmp.first+tmp.second << endl;
}