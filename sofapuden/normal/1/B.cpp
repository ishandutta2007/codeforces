#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	string s; cin >> s;
	string csr[4];
	int number = 0;
	for(char c : s){
		if(number%2 == 0){
			if(isdigit(c)){
				number++;
			}
		}
		else{
			if(isalpha(c)){
				number++;
			}
		}
		csr[number]+=c;
	}
	if(number == 1){
		reverse(all(csr[0]));
		int ans = 0;
		for(int i = 0, multi = 1; i < csr[0].length(); ++i,multi*=26){
			ans+=(multi)*(csr[0][i]-'A'+1);
		}
		cout << "R" + csr[1] + "C" << ans << "\n";
	}
	else{
		int nutode = stoi(csr[3]);
		string ans = "";
		while(nutode > 0){
			ans = char((nutode-1)%26 + 'A') + ans;
			nutode -= ((nutode-1)%26+1);
			nutode/=26;
		}
		cout << ans << csr[1] << "\n";
	}
			

			
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; cin >> t; while(t--){
		solve();
	}
		
	return 0;
}