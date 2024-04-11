#include <bits/stdc++.h>



#define NN 1000111

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char s[NN];

int ans[NN], ed[NN];



int main() {

	scanf("%s", s+1);

	int n=strlen(s+1), i, j;

	

	for(i=1; i<=n; i++) {

		ed[i]=ed[i-1];

		if(s[i]=='F') ed[i]++;

	}

	

//	for(i=1; i<=n; i++) cout<<i<<' '<<ed[i]<<endl;

	ans[0]=-1;

	i=1;

	while(s[i]=='F') i++;

	for(; i<=n; i++){

		if(s[i]=='M') ans[i]=ans[i-1];

		else {

			if(i-ed[i]<=ans[i-1]) ans[i]=ans[i-1]+1;

			else ans[i]=i-ed[i];

		}

	}

	cout<<max(0, ans[n])<<endl;

	



	return 0;

}