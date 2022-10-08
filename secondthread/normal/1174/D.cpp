#include <bits/stdc++.h>

using namespace std;

int logBase2(int n) {
	for (int i=31; i>0; i--)
		if (n&(1<<i))
			return i;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int nBits, illegal; cin>>nBits>>illegal;
	vector<int> realBits;
	int illegalBit=logBase2(illegal);
	for (int i=0; i<31; i++)
		if (i!=illegalBit)
			realBits.push_back(1<<i);
	if (illegal>=(1<<nBits)) {
		cout<<(1<<nBits)-1<<'\n';
		for (int i=1; i<(1<<nBits); i++) {
			cout<<(i&-i)<<" \n"[i==(1<<nBits)-1];
		}
	}
	else {
		nBits--;
		cout<<(1<<nBits)-1<<'\n';
		for (int i=1; i<(1<<nBits); i++) {
			cout<<realBits[__builtin_ctz(i&-i)]<<" \n"[i==(1<<nBits)-1];
		}

	}

	return 0;
}