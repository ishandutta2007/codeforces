#include <bits/stdc++.h>

using namespace std;
const int maxn=200001;

bool used[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	string st;
	cin>>st;
	int deleted=0;
	for (int i=0; i<n; i++) used[i]=true;

	for (int i=0; i+1<n; i++) {
		if (st[i]!=st[i+1]) {
			used[i]=used[i+1]=true;
			i++;
			continue;
		}
		used[i]=false;
		deleted++;
	}
	if (((deleted^n)&1)!=0) {
		used[n-1]=false;
		deleted++;
	}
	cout<<deleted<<endl;
	for (int i=0; i<n; i++)
		if (used[i]) cout<<st[i];
	cout<<endl;

	return 0;
}