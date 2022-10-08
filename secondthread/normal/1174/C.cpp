#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn=100001;

bool isPrime[maxn]={0};

map<int, int> primeIndex;
void precomp() {
	for (int i=2; i<maxn; i++)
		isPrime[i]=true;
	int primesSeen=0;
	for (int i=2; i<maxn; i++) {
		if (!isPrime[i]) continue;
		primesSeen++;
		primeIndex.insert({i, primesSeen});
		for (ll j=i*(long long)i; j<maxn; j+=i)
			isPrime[j]=false;
	}

}

int main() {
	precomp();
	int n; cin>>n;
	int max=0;
	for (int i=2; i<=n; i++) {
		bool found=false;
		for (int j=2; j*(ll)j<=i; j++) {
			if (i%j==0) {
				found=true;
				cout<<primeIndex[j]<<" \n"[i==n];
				break;
			}
		}
		if (!found) {
				cout<<primeIndex[i]<<" \n"[i==n];
		}
	}

	return 0;
}