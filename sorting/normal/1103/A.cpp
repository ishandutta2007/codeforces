#include <bits/stdc++.h>

using namespace std;

const long long N = 1007;
const long long M = (1 << 16) + 7;

string s;
bool board[5][5];

bool place(bool horizontal, long long x, long long y){

	if(board[x][y]){
		return false;
	}

	if(!horizontal){
		if(x == 3 || board[x+1][y]){
			return false;
		}

		board[x][y] = true;
		board[x+1][y] = true;
	}else{
		if(y == 3 || board[x][y+1]){
			return 0;
		}

		board[x][y] = true;
		board[x][y+1] = true;
	}

	return true;
}

void remove_tiles(){
	bool row[4], col[4];

	for(int i = 0; i < 4; i++){
		row[i] = true;
		col[i] = true;
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(!board[i][j]){
				row[i] = false;
				col[j] = false;
			}
		}
	}

	for(int i = 0; i < 4; i++){
		if(row[i]){
			for(int j = 0; j < 4; j++){
				board[i][j] = false;
			}
		}
		if(col[i]){
			for(int j = 0; j < 4; j++){
				board[j][i] = false;
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	for(int i = 0; i < s.size(); i++){

		bool done = false;

		if(s[i] == '1'){
			for(int x = 0; x < 4 && !done; x++){
				for(int y = 0; y < 4 && !done; y++){
					if(place(s[i] - '0', x, y)){
						done = true;
						cout << x+1 << " " << y+1 << "\n";
						break;
					}
				}
			}
		}else{
			for(int x = 0; x < 4 && !done; x++){
				for(int y = 0; y < 4 && !done; y++){
					if(place(s[i] - '0', y, x)){
						done = true;
						cout << y+1 << " " << x+1 << "\n";
						break;
					}
				}
			}
		}

		remove_tiles();
	}

	return 0;
}