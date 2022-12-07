#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (1LL << 55)
#define MOD (1000 * 1000 * 1000 + 7)
#define maxn 200111

typedef long long ll;
typedef long double ld;

string str[10];

int main(){
	for(int i = 0; i < 9; i++){
		string s;
		for(int j = 0; j < 3; j++){
			cin >> s;
			str[i] += s;
		}
	}

	int x, y;
	cin >> x >> y;
	x--; y--;
	x %= 3;
	y %= 3;


	int cnt = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int nx = 3 * x + i;
			int ny = 3 * y + j;
			if(str[nx][ny] == '.'){
				cnt++;
				str[nx][ny] = '!';
			}
		}
	}

	if(cnt == 0){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				int nx = i;
				int ny = j;
				if(str[nx][ny] == '.'){
					str[nx][ny] = '!';
					cnt++;
				}
			}
		}
	}

	for(int i = 0; i < 9; i++){
		if(i == 3 || i == 6)
			cout << endl;

		for(int j = 0; j < 9; j++){
			if(j == 3 || j == 6)
				cout << " ";

			cout << str[i][j];
		}
		cout << endl;
	}
	return 0;
}