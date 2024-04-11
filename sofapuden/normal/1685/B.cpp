#include<bits/stdc++.h>

using namespace std;

void solve(){
	int a, b, c, d; cin >> a >> b >> c >> d;
	string s; cin >> s;
	int tota = a + c + d;
	int totb = b + c + d;
	for(auto x : s){if(x == 'A')tota--; else totb--;}
	if(tota|totb){
		cout << "NO\n";
		return;
	}
	int n = a+b+2*c+2*d;
	int cn = 1;
	int jok = 0;
	for(int i = 1; i < n; ++i){
		if(s[i] != s[i-1]){
			cn++;
			continue;
		}
		if(cn == 1)continue;
		if(cn == 2){
			if(s[i] == 'A')d--;
			else c--;
			cn = 1;
			continue;
		}
		if(cn&1){
			jok+=cn/2;
			cn = 1;
			continue;
		}
		cn = 1;
	}
	if(cn == 2){
		if(s.back() == 'A')d--;
		else c--;
	}
	if(cn&1){
		jok+=cn/2;
	}
	d = max(d,0);
	c = max(c,0);
	cn = 1;
	vector<int> v1, v2;
	for(int i = 1; i < n; ++i){
		if(s[i] != s[i-1]){
			cn++;
			continue;
		}
		if(cn == 1)continue;
		if(cn == 2){
			cn = 1;
			continue;
		}
		if(cn&1){
			cn = 1;
			continue;
		}
		if(s[i] == 'A'){
			v1.push_back(cn/2);
			cn = 1;
		}
		else{
			v2.push_back(cn/2);
			cn = 1;
		}
	}
	if(!(cn&1) && cn != 2){
		if(s.back() == 'A'){
			v1.push_back(cn/2);
		}
		else{
			v2.push_back(cn/2);
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(auto x : v1){
			int z = min(d,x);
			d-=z;
			c-=min(c,max(0,x-z-1));
	}
	for(auto x : v2){
			int z = min(c,x);
			c-=z;
			d-=min(d,max(0,x-z-1));
	}
	if(jok >= c+d){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}

}

int main(){
	int t; cin >> t;
	while(t--)solve();


}