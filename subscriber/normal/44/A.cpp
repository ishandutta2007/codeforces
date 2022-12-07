#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;

map<pair<string,string>,int> m;
int n,ans=0;
string a,b;

int main(void){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a >> b;
		if (!m[make_pair(a,b)])ans++;
		m[make_pair(a,b)]=1;
	}			
	cout << ans << endl;
	return 0;
}