//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e3 + 20;
string S[Maxn];
int score[Maxn];
int n,m;
int find(string P){
	for(int i = 0; i < n;i++){
		if(P == S[i])
			return i;
	}
	return n++;
}
int main(){
	cin >> m;
	for(int i = 0; i < m;i++){
		string name;
		int scr;
		cin >> name >> scr;
		int num = find(name);
		S[num] = name;
		score[num] = max(score[num],scr);
	}
	cout << n << endl;
	for(int i = 0; i < n;i++){
		long double better = 0;
		for(int j = 0; j < n;j++){
			if(score[j] > score[i])
				better++;
		}
		long double worse = n - better;
		cout << S[i] << ' ';
		if(better/n > 0.5){
			cout << "noob" << endl;
		}else if(better/n > 0.2){
			cout << "random" << endl;
		}else if(better/n > 0.1){
			cout << "average" << endl;
		}else if(better/n > 0.01){
			cout << "hardcore" << endl;
		}else{
			cout << "pro" << endl;
		}
	}
	return 0;
}