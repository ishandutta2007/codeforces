#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

int n,m,x,l,r;
string s1,s2,s3,s4;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	l=n;
	r=1;
	for (int i=0;i<m;i++){
		cin >> s1 >> s2 >> s3 >> s4 >> x;
		if (s3=="left")l=min(l,x-1);else r=max(r,x+1);
	}
	if (r>l)puts("-1");else cout << l-r+1;
	return 0;
}