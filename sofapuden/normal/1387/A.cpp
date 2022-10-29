#include <bits/stdc++.h>

using namespace std;

typedef double db;

int n, m;
vector<vector<pair<int,int>>> gra;
vector<db> ans;
vector<int> colors;
vector<int> nums;
set<int> ansvis, recvis, fillvis;
db sum;
int index1;

void ansfill(int ind, db val){
	ansvis.insert(ind);
	ans[ind] = val;
	for(int i = 0; i < (int)gra[ind].size(); ++i){
		if(ans[gra[ind][i].first] == -0.25)ansfill(gra[ind][i].first, gra[ind][i].second - val);
		else if(val+ans[gra[ind][i].first] != gra[ind][i].second){
			cout << "NO\n"; 
			exit(0);
		}
	}
}
int rec(int ind, int k){
	recvis.insert(ind);
	colors[ind] = k;
	for(int i = 0; i < (int)gra[ind].size(); ++i){
		if(recvis.count(gra[ind][i].first)){
			if(k == colors[gra[ind][i].first]){
				sum+=gra[ind][i].second;
				index1 = gra[ind][i].first;
				if(ind == index1)return -2;
				return gra[ind][i].first;
			}
		}
		else{
			int v = rec(gra[ind][i].first, !k);
			if(v == ind){
				sum+=gra[ind][i].second;
				return -2;
			}
			if(v == -1)continue;
			if(v == -2)return v;
			sum+=gra[ind][i].second*(k == colors[v] ? 1 : -1);
			return v;
		}
	}
	return -1;
}

void recfill(int ind, int k, int val){
	fillvis.insert(ind);
	nums.push_back(val * (k ? 1 : -1));
	for(int i = 0; i < (int)gra[ind].size(); ++i){
		if(!fillvis.count(gra[ind][i].first)){
			recfill(gra[ind][i].first, !k, gra[ind][i].second - val);
		}
	}
}
void fill(int ind){
	nums.clear();
	recfill(ind, 0, 0);
	sort(nums.begin(), nums.end());
	ansfill(ind, nums[nums.size()/2]);
}
	
					
int check(int ind){
	sum = 0;
	index1 = -1;
	int v = rec(ind, 0);
	if(v == -1)return 0;
	ansfill(index1, sum/2);
	return 1;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	gra.resize(n);
	ans.resize(n, -0.25);
	colors.resize(n, -1);
	while(m--){
		int nm1, nm2, nm3; cin >> nm1 >> nm2 >> nm3;
		nm1--; nm2--;
		gra[nm1].push_back(make_pair(nm2, nm3));
		gra[nm2].push_back(make_pair(nm1, nm3));
	}
	for(int i = 0; i < n; ++i){
		if(!ansvis.count(i)){
			if(!check(i))fill(i);
		}
	}
	cout << "YES\n";
	for(db i : ans)cout << i << " ";
	cout << "\n";
	return 0;
}