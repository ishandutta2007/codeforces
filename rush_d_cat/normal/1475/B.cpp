#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; cin>>t;
    while(t--) {
    	LL n; cin>>n;
    	bool ok = false;
    	for(int x=0;x*2020<=n;x++){
    		if((n-x*2020)%2021==0) ok=true;
    	}
    	cout<<(ok?"YES\n":"NO\n");
    }
}