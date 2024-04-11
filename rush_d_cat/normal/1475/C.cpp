#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);	
    int t;
   	cin >> t;
   	while (t --) {
   		LL a,b,k; cin>>a>>b>>k;
   		LL ans=k*(k-1)/2;
   		map<int,int> mp;
   		for(int i=1;i<=k;i++){
   			int x; cin>>x; mp[x]++;
   		}
   		for(auto p: mp) {
   			ans -= 1LL*p.second*(p.second-1)/2;
   		}
   		mp.clear();
   		for(int i=1;i<=k;i++){
   			int x; cin>>x; mp[x]++;
   		}
   		for(auto p: mp) {
   			ans -= 1LL*p.second*(p.second-1)/2;
   		}
   		cout<<ans<<endl;
   	}
}