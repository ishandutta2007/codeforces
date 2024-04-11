#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char s[NN];



int main() {

	int n;

	scanf("%s" ,s);

	

	int ans=0;

	char st='a';

	for(int i=0; i<strlen(s); i++){

		char tmp=s[i];

		if(tmp>st) swap(tmp,  st);

		ans+=min(st-tmp, (tmp+26-st)%26);

		st=s[i];

	}

	cout<<ans<<endl;



	return 0;

}