#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int data[8];
	for(int i = 0; i < 8; ++i){
		cin >> data[i];
	}
	cout << min((data[1]*data[2])/data[6],min(data[3]*data[4],data[5]/data[7]))/data[0] << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}