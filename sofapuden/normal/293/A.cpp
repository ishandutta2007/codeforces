#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define vvi vector<vector<int>>
#define vi vector<int>
#define MAXSIZE 100000000
using namespace std;

int main(){

	int N;
	cin >> N;
	string s1, s2;
	cin >> s1 >> s2;
	int sum = 0;
	int draw = 0;
	rep(i, 0, s1.length()) {
		if (s1[i] == '1') {
			sum++;
		}
		if (s2[i] == '1') {
			sum--;
		}
		if (s1[i] == '1' && s2[i] == '1') {
			draw++;
		}
	}
	cout << (sum == 0 ? draw % 2 == 0 ? "Draw\n" : "First\n" : sum == -2 ? draw % 2 == 1 ? "Draw\n" : "Second\n" : sum == -1 ? "Draw\n": sum > 0 ? "First\n" : "Second\n");

}