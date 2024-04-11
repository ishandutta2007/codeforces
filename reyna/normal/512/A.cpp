//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 123;
string S[Maxn];
int mat[26][26];
int b[26];
bool cmp[Maxn][Maxn];
int Que[Maxn*Maxn];
int begin,end;
vector<int> ans;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		cin >> S[i];
	}
	for(int i = 1; i < n;i++)
		cmp[0][i] = 1;
	for(int j = 0; j < 200;j++){
		for(int i = 1; i < n;i++){
			if(!cmp[j][i])
				continue;
			if(S[i].size() <= j && S[i-1].size() >= j){
				cout << "Impossible" << endl;
				return 0;
			}
			if((S[i].size() <= j || S[i-1].size() <= j))
				continue;
			if(S[i][j] == S[i-1][j]){
				cmp[j+1][i] = 1;
			}else if(S[i][j] != S[i-1][j]){
				if(!mat[S[i-1][j]-'a'][S[i][j]-'a'])
					b[S[i][j]-'a']++;
				mat[S[i-1][j]-'a'][S[i][j]-'a'] = 1;
			}
		}
	}
	for(int i = 0; i < 26;i++){
		if(b[i] == 0)
			Que[end++] = i;
	}
	int cnt = 0;
	while(end != begin){
		cnt++;
		int now = Que[begin++];
		ans.push_back(now);
		for(int i = 0; i < 26;i++){
			if(mat[now][i]){
				b[i]--;
				if(!b[i]){
					Que[end++] = i;
				}
			}
		}
	}
	if(cnt != 26){
		cout << "Impossible" << endl;
		return 0;
	}
	for(int i = 0; i < cnt;i++){
		cout << char(ans[i]+'a');
	}
	cout << endl;
	return 0;
}