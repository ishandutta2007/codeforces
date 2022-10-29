#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	
}

int main(){
	vi v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(),v.end());
	cout << max((v[2]-v[0]-v[1] + 1),0) << "\n";	
}