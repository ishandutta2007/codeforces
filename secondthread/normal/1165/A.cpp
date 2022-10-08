#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);	
	int n, rem, mod; cin>>n>>mod>>rem;
	string st; cin>>st;
	int count=0;
	for (int i=0; i<rem; i++)
		if (st[st.length()-1-i]!='0')
			count++;
	if (st[st.length()-1-rem]!='1') count++;
	for (int i=rem+1; i<mod; i++)
		if (st[st.length()-1-i]!='0')
			count++;
	cout<<count<<endl;


	return 0;
}