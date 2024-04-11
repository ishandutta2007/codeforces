#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x). rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n; cin >> n;
	int p1 = 0, p2 = n-1;
	vi v;
	for(int i = 0, tmp; i < n; ++i){
		cin >> tmp;
		v.push_back(tmp);
	}
	int score[2];
	for(int i = 0; i < 2; ++i){
		score[i] = 0;
	}
	int cnt = 0;
	while(p1 != p2){
		if(v[p1] < v[p2]){
			score[cnt%2]+=v[p2];
			p2--;
		}
		else{
			score[cnt%2]+=v[p1];
			p1++;
		}
		cnt++;
	}
	score[cnt%2]+=v[p1];
	cout << score[0] << " " << score[1] << "\n";
		
		
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}