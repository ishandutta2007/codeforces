#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<string> v1(n), v2(n), v3(n);
	map<string,int> M;
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		v1[i] = s;
		M[s]++;
	}
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		v2[i] = s;
		M[s]++;
	}
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		v3[i] = s;
		M[s]++;
	}
	int a1 = 0, a2 = 0, a3 = 0;
	for(int i = 0; i < n; ++i){
		if(M[v1[i]] == 1)a1+=3;
		else if(M[v1[i]] == 2)a1++;
		if(M[v2[i]] == 1)a2+=3;
		else if(M[v2[i]] == 2)a2++;
		if(M[v3[i]] == 1)a3+=3;
		else if(M[v3[i]] == 2)a3++;
	}
	cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}