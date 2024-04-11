#include <bits/stdc++.h>

using namespace std;
const int maxn=500001;

int a[maxn];
int find(int i) {
	if (a[i]<0) return i;
	return a[i]=find(a[i]);
}
void comb(int i, int j) {
	i=find(i);
	j=find(j);
	if (i==j) return;
	if (i<j) {
		//i is bigger
		a[i]+=a[j];
		a[j]=i;
	}
	else {
		a[j]+=a[i];
		a[i]=j;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin>>n>>m;
	for (int i=0; i<n; i++) a[i]=-1;
	for (int i=0; i<m; i++) {
		int nAdj; cin>>nAdj;
		int first;
		if (nAdj!=0) cin>>first;
		for (int j=1; j<nAdj; j++) {
			int next; cin>>next;
			comb(first-1, next-1);
		}
	}
	for (int i=0; i<n; i++) {
		cout<<-a[find(i)]<<" \n"[i==n-1];
	}
	
	return 0;
}