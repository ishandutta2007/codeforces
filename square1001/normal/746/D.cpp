#include <string>
#include <iostream>
using namespace std;
int main() {
	int N, K, A, B;
	cin >> N >> K >> A >> B;
	int cont = 0;
	string ans;
	for(int i = 0; i < N; ++i) {
		if(A > B) {
			if(cont != K || (i >= 1 && ans[i - 1] == 'B')) ans += "G", --A;
			else ans += "B", --B;
		}
		else {
			if(cont != K || (i >= 1 && ans[i - 1] == 'G')) ans += "B", --B;
			else ans += "G", --A;
		}
		if(i >= 1 && ans[i] != ans[i - 1]) cont = 1;
		else ++cont;
	}
	cout << (A == 0 && B == 0 ? ans : "NO") << endl;
	return 0;
}