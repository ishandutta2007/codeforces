#include <bits/stdc++.h>

using namespace std;

const int N = 107;

char s[N][N];
int cnt[N][N];
pair<int, int> left_corner[N][N];

char get_letter(char a = ' ', char b = ' ', char c = ' '){
	char res = 'A';

	for(int i = 0; i < 3; i++, res++){
		if(res != a  && res != b && res != c){
			break;
		}
	}

	return res;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for(int i = 0; i <= n + 3; i++){
		for(int j = 0; j <= m + 3; j++){
			s[i][j] = ' ';
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//cout << i << " i j " << j << "\n"; 

			if(s[i][j] == ' '){
				if(j != 1 && s[i][j-1] < get_letter(s[i][j-1], s[i-1][j], s[i][j+1])){
					pair<int, int> p = left_corner[i][j-1];
					int cnt_p = cnt[p.first][p.second];
					bool possible = true;

					if(p.first + cnt_p > n || p.second + cnt_p > m){
						possible = false;
					}

					for(int i2 = p.first; i2 < p.first + cnt_p + 1; i2++){
						if(s[i2][p.second + cnt_p] != ' '){
							possible = false;
							break;
						}
						if(s[i2][p.second + cnt_p + 1] == s[p.first][p.second]){
							possible = false;
							break;
						}
						if(s[i2 + 1][p.second + cnt_p] == s[p.first][p.second]){
							possible = false;
							break;
						}
					}

					for(int j2 = p.second; j2 < p.second + cnt_p + 1; j2++){
						if(s[p.first + cnt_p][j2] != ' '){
							possible = false;
							break;
						}
						if(s[p.first + cnt_p + 1][j2] == s[p.first][p.second]){
							possible = false;
							break;
						}
						if(s[p.first + cnt_p][j2 + 1] == s[p.first][p.second]){
							possible = false;
							break;
						}
					}

					if(s[p.first + cnt_p][p.second - 1] == s[p.first][p.second]){
						possible = false;
					}
					if(s[p.first - 1][p.second + cnt_p] == s[p.first][p.second]){
						possible = false;
					}

					if(possible){
						//cout << i << " " << j << endl;
						for(int i2 = p.first; i2 < p.first + cnt_p + 1; i2++){
							s[i2][p.second + cnt_p] = s[p.first][p.second];
							left_corner[i2][p.second + cnt_p] = p;
						}

						for(int j2 = p.second; j2 < p.second + cnt_p + 1; j2++){
							s[p.first + cnt_p][j2] = s[p.first][p.second];
							left_corner[p.first + cnt_p][j2] = p;
						}

						cnt[p.first][p.second]++;

						continue;
					}
				}

				//cout << i << " - " << j << endl;

				s[i][j] = get_letter(s[i][j-1], s[i-1][j], s[i][j+1]);
				cnt[i][j] = 1;
				left_corner[i][j] = {i, j};
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << s[i][j];
		}
		cout << "\n";
	}

	return 0;
}