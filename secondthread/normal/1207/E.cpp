
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout<<"? ";
	for (int i=0; i<100; i++) cout<<i<<" ";
	cout<<endl;
	cout<<"? ";
	for (int i=1; i<101; i++) cout<<(i<<7)<<" ";
	cout<<endl;
	fflush(stdout);
	int a, b;
	cin>>a>>b;
	//highest 7 bits from a, lowest 7 from b;
	int mask=(1<<7)-1;
	int ans=(a&(~mask)) | (b&mask);
	cout<<"! "<<ans<<endl;
	fflush(stdout);
	return 0;
}