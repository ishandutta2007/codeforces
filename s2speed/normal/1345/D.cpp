#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	set<ll> sa , sb;
	bool h = false;
	string s[1000];
	ll n , m , ch , ans = 0;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		ch = 0;
		cin>>s[i];
		for(int j = 0 ; j < m ; j++){
			if((ch == 0 && s[i][j] == '#') || (ch == 1 && s[i][j] == '.') || (ch == 2 && s[i][j] == '#')){
				ch++;
			}
		}
		if(ch == 3){
			cout<<-1<<endl;
			return 0;
		}
		if(ch == 0){
			sa.insert(i);
		}
	}
	for(int j = 0 ; j < m ; j++){
		ch = 0;
		for(int i = 0 ; i < n ; i++){
			if((ch == 0 && s[i][j] == '#') || (ch == 1 && s[i][j] == '.') || (ch == 2 && s[i][j] == '#')){
				ch++;
			}
		}
		if(ch == 3){
			cout<<-1<<endl;
			return 0;
		}
		if(ch == 0){
			sb.insert(j);
		}
	}
	if((sa.size() == 0 && sb.size() > 0) || (sa.size() > 0 && sb.size() == 0)){
		cout<<-1<<endl;
		return 0;
	}
	for(int i = 0 ; i < n - 1 ; i++){
		if(sa.find(i) != sa.end()){
			continue;
		}
		if(h == false){
			ans++;
		}
		h = false;
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '#' && s[i + 1][j] == '#'){
				h = true;
				break;
			}
		}
	}
	if(h == false && sa.find(n - 1) == sa.end()){
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}