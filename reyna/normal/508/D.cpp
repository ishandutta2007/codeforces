//In the name of God
// I read the idea in the comments.. i hope there will be a feature that avoid spoiling problems XD
#include <iostream>
#include <vector>
using namespace std;
vector<int> faketour;
vector<int> tour;
const int Maxn = 62 * 62 + 10;
vector<int> al[Maxn];
int mat[Maxn][Maxn];
int in[Maxn];
int out[Maxn];
int cnt1 = 0;
int cnt2 = 0;
int src = 0;
int findc(char S){
	if('0' <= S && S <= '9'){
		return S - '0' + 52;
	}
	if('a' <= S && S <= 'z'){
		return S - 'a' + 26;
	}
	if('A' <= S && S <= 'Z')
		return S - 'A';
	return -1000;
}
int find(char a,char b){
	return findc(a) * 62 + findc(b);
}
void dfs(int v){
	for(int u = 0; u < Maxn;u++){
		if(mat[v][u]){
			mat[v][u]--;
			dfs(u);
		}
	}
	faketour.push_back(v);
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		string S;
		cin >> S;
		mat[find(S[0],S[1])][find(S[1],S[2])]++;
		out[find(S[0],S[1])]++;
		in[find(S[1],S[2])]++;
		src = find(S[0],S[1]);
	}
	for(int i = 0; i < Maxn;i++){
		if(in[i] < out[i]){
			cnt1++;
			src = i;
		}else if(in[i] > out[i]){
			cnt2++;
		}
	}
	if((cnt1 == 1 && cnt2 == 1 || cnt1 == 0 && cnt2 == 0)){
		dfs(src);
		if(n+1 != faketour.size()){
			cout << "NO" << endl;
			return 0;
		}
		n = faketour.size();
		for(int i = n-1;i >= 0;i--){
			tour.push_back(faketour[i]);
		}
	}else{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	string S = "";
	bool f = 0;
	for(int i = 0; i < 256 && !f;i++){
		for(int j = 0; j < 256;j++){
			S = "";
			S+=char(i);
			S+=char(j);
			if(find(S[0],S[1]) == tour[0]){
				cout << S;
				f = 1;
				break;
			}
		}
	}
	for(int i = 1; i < n;i++){
		for(int j = 0; j < 256;j++){
			if(findc(char(j)) == tour[i] % 62){
				cout << char(j);
				break;
			}
		}
	}
	cout << endl;
	return 0;
}