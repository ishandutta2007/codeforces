#include <bits/stdc++.h>

using namespace std;
const int maxn=200001;

int a[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);	
	int n; cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
	sort(a, a+n);
	int index=0;
	int count=0;
	for (int day=1; day<=n; day++) {
		while(index<n&&a[index]<day) index++;
		if (index<n) {
			index++;
			count++;
		}
	}
	cout<<count<<endl;

	return 0;
}