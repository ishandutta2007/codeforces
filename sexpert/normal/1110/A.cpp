#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int rep[MAXN];

int main() {
	int b, k;
	cin >> b >> k;
	for(int i = 0; i < k; i++)
	    cin >> rep[i];
	if(b % 2 == 0) {
	    if(rep[k - 1] % 2)
	        cout << "odd\n";
	    else
	        cout << "even\n";
	    return 0;
	}
	int p = 0;
	for(int i = 0; i < k; i++) {
	    if(rep[i]%2)
	        p++;
	}
	if(p % 2 == 1)
	    cout << "odd\n";
	else
	    cout << "even\n";
}