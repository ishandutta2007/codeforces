#include<bits/stdc++.h>
using namespace std;

const int MAX=2000001;
const int OFFSET=1000000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> a(n);
		for (int i=0; i<n; i++) {
		    cin>>a[i];
		    a[i]=abs(a[i]);
		}
		
		bitset<MAX> reachable;
		bitset<MAX> next;
		
		reachable[OFFSET]=true;
		bool works=false;
		for (int i:a) {
			if (reachable[OFFSET+i]) works=true;
			next=reachable|(reachable<<i)|(reachable>>i);
			swap(reachable, next);
		}
		
		cout<<(works?"YES":"NO")<<'\n';
    }
}