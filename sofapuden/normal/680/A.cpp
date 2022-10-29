#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	map<int,int> M;
	M[a]++;
	M[b]++;
	M[c]++;
	M[d]++;
	M[e]++;
	int ans = 0;
	if(M[a] >= 3){
		ans = max(ans,a*3);
	}
	else if(M[a] == 2){
		ans = max(ans,a*2);
	}
	if(M[b] >= 3){
		ans = max(ans,b*3);
	}
	else if(M[b] == 2){
		ans = max(ans,b*2);
	}
	if(M[c] >= 3){
		ans = max(ans,c*3);
	}
	else if(M[c] == 2){
		ans = max(ans,c*2);
	}
	if(M[d] >= 3){
		ans = max(ans,d*3);
	}
	else if(M[d] == 2){
		ans = max(ans,d*2);
	}
	cout << a + b + c + d + e - ans << '\n';
}