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
	int t;
	cin >> t;

	while (t--) {
		int N;
		vi v1;
		vi v2;
		cin >> N;
		rep(i, 0, N) {
			int tmp;
			cin >> tmp;
			v1.push_back(tmp);
		}
		rep(i, 0, N) {
			int tmp;
			cin >> tmp;
			v2.push_back(tmp);
		}
		sort(all(v2));
		sort(all(v1));
		LOG_vec(v1, " ");
		LOG_vec(v2, " ");
	}

}