//In the name of God
#include <bits/stdc++.h>
using namespace std;
int sum = 0;
void winner(int x){
	if((sum + x) % 2 == 0) cout << "Daenerys";
	else cout << "Stannis";
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	k = n - k;
	int o = 0,e = 0;
	for(int i = 0; i < n;i++){
		int p;
		cin >> p;
		sum += p % 2;
		sum %= 2;
		o += p % 2;
		e += !(p % 2);
	}
	if(!k){
		winner(0);
		return 0;
	}
	int last = k & 1;
	if(last){
		if(e <= (k ) / 2){
			winner((k - e) & 1);
		}else if(o <= (k ) / 2){
			winner(o & 1);
		}else{
			cout << "Stannis\n";
		}
	}else{
		if(e <= k / 2){
			winner((k - e) & 1);
		}else if(o <= k / 2){
			winner(o & 1);
		}else{
			cout << "Daenerys\n";
		}
	}
	return 0;
}