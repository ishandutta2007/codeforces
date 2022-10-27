#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    LL t;
    cin >> t;
    while (t --) {
    	LL x; cin>>x;
    	while(x%2==0)x/=2;
    	cout<<(x==1?"NO":"YES")<<endl;
    }
}