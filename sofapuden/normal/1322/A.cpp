#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	int N;
	cin >> N;
	string s;
	cin >> s;
	int sum = 0;
	int counter = 0;
	int first = 0;
	int second = 0;
	rep(i, 0, N) {
		if (s[i] == '(') {
			first++;
			counter++;
			sum += (counter <= 0 ? 1 : 0);
		}
		else {
			second++;
			counter--;
			sum += (counter < 0 ? 1 : 0);
		}

	}
	cout << (first == second?sum:-1);

}