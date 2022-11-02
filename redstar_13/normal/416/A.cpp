#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;





int main() {

	int n,i,j;

	cin>>n;

	

	char s[10], key;

	int st=-1000001000, ed=1002000000;

	

	for(i=0; i<n; i++){

		int u;

		scanf("%s %d %c", s, &u, &key);

		if(!strcmp(s, ">=")) {

			if(key=='Y') st=max(st, u);

			else ed=min(ed, u-1);

		}

		if(!strcmp(s, "<=")) {

			if(key=='Y') ed=min(ed, u);

			else st=max(st, u+1);

		}

		if(!strcmp(s, ">")) {

			if(key=='Y') st=max(st, u+1);

			else ed=min(ed, u);

		}

		if(!strcmp(s, "<")) {

			if(key=='Y') ed=min(ed, u-1);

			else st=max(st, u);

		}

	}

	if(st>ed) puts("Impossible");

	else cout<<st<<endl;





	return 0;

}