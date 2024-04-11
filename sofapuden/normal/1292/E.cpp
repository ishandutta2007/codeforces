#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

char ou[100];
int n;

int query(string s){
	cout << "? " << s << endl;
	int nu; cin >> nu;
	if(nu == -1)exit(0);
	for(int i = 0; i < nu; ++i){
		int pos; cin >> pos;
		for(int j = 0; j < s.size(); ++j){
			ou[pos+j] = s[j];
		}
	}
	return nu;
}

void ans(){
	cout << "! ";
	for(int i = 1; i <= n; ++i){
	       cout << ou[i];
	}
	cout << endl;
	int x; cin >> x;
	if(x == 0)exit(0);
}

void solve(){
	cin >> n;
	for(int i = 0; i < 100; ++i){
		ou[i] = '?';
	}
	int r;
	if(!(query("CH")+query("CO")+query("HC")+query("HO"))){
		if(query("CCC") || query("HHH")){
			r = n;
			while(ou[r] != '?'){
				--r;
			}
			while(r){
				ou[r--] = 'O';
			}
			ans();
			return;
		}
		else if(query("OOO")){
			string now = "";
			r = 1;
			while(ou[r] != '?'){
				now+='O';
				++r;
			}
			int pos = r;
			while(r <= n){
				now+='H';
				++r;
			}
			if(!query(now)){
				while(pos <= n){
					ou[pos++] = 'C';
				}
			}
			ans();
			return;
		}
		else{
			if(!query("OOHH")){
				ou[1] = ou[2] = 'O';
				ou[3] = ou[4] = 'C';
			}
			ans();
			return;
		}
	}
	else{
		string now = "";
		r = n;
		while(ou[r] == '?'){
			--r;
		}
		now=ou[r];
		for(int i = r-1; i; --i){
			if(ou[i] == '?'){
				if(ou[i+1] == 'O')ou[i] = 'O';
				else{
					query(ou[i+1]+now); 
					if(ou[i] == '?')ou[i] = 'O';
				}
			}
			now = ou[i] + now;
		}
		for(int i = r+1; i <= n; ++i){
			if(ou[i-1] == 'H')ou[i] = 'H';
			else if(ou[i-1] == 'C')ou[i] = 'C';
			else{
				query(now+'O');
				if(ou[i] == '?'){
					for(int j = i; j <= n; ++j)now+='H';
					if(!query(now))for(int j = i; j <= n;++j)ou[j] = 'C';
				}
			}
			now = now + ou[i];
		}
		ans();
		return;
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}