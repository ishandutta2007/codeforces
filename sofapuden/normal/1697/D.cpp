#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

char que1(int x){
	cout <<  "? 1 " << x+1 << endl;
	char c; cin >> c;
	return c;

}

int que2(int l, int r){
	cout << "? 2 " << l+1 << ' ' << r+1 << endl;
	int x; cin >> x;
	return x;
}

void solve(){
	int n; cin >> n;
	string s(n,'?');
	for(int i = 0; i < n; ++i){
		int cn = 0;
		char cu = '?';
		for(int j = 5; ~j; --j){
			cn+=(1<<j);
			set<char> in;
			char lst = '?';
			int ind = 0;
			for(int k = i-1; ~k; --k){
				ind = k;
				if(!in.count(s[k])){
					in.insert(s[k]);
					lst = s[k];
				}
				if((int)in.size() == cn-1)break;
			}
			if(in.size() != cn-1){
				cn-=(1<<j);
				continue;
			}
			int z = que2(ind,i);
			if(z != cn){
				cn-=(1<<j);
				cu = lst;
			}
		}
		if(cu != '?')s[i] = cu;
		else s[i] = que1(i);
	}
	cout << "! " << s << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--)solve();
}