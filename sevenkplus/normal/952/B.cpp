#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
	int no = 0;
	for (int i = 0; i < 10; i ++) {
		printf ("%d\n", i);
		fflush(stdout);
		string s;
		getline(cin, s);
		if (s == "no") no++;
		if (s == "worse" || s == "are you serious?" || s == "go die in a hole" || s == "terrible" || s == "no way" || s == "don't even") {
			puts ("grumpy"); 
			break;
		}
		if (s == "cool" || s == "not bad" || s == "don't touch me!" || s == "don't think so" || s == "great!" || no == 4) {
			puts ("normal");
			break;
		}
	}
	return 0;
}