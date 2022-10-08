#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a[3], d; cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a, a+3);
	int total=0;
	total+=max(0, d-(a[1]-a[0]));
	total+=max(0, d-(a[2]-a[1]));
	cout<<total<<endl;


	return 0;
}