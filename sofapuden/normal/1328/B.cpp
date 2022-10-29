#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define in(name, type) type name; cin >> name
#define LOG(x, sep) std::cout << x << sep
#define LOG(x) std::cout << x << "\n"
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

int main() {

	int t;
	cin >> t;

	rep(i, 0, t) {
		int n, k, counter,pls,why, counter2;
		string result = "";
		cin >> n >> k;
		counter = 1;
		pls = 1;
		why = 0;
		while (counter>0) {
			rep(j,0,counter){
				if (pls == k) {
					why = 1;
					counter2 = j;
					break;
				}
				pls++;
			}
			if (pls == k && why == 1) {
				break;
			}
			counter++;
		}
		rep(i, 0, n) {
			result.append("a");
		}
		result[n-counter-1] = 'b';
		result[n-counter2-1] = 'b';
		cout << result << "\n";
	}


	return 0;
}