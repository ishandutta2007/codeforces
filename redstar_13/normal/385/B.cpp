#include <bits/stdc++.h>



#define NN 5555

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char s[NN];

int flag[NN], nxt[NN];



int main() {

	

	scanf("%s", s);

	int n=strlen(s), i, j;

	for(i=0; i<n-3; i++){

		int ok=1;

		for(j=0; j<4; j++){

			if(s[i+j]!="bear"[j]) ok=0;

		}

		if(ok) flag[i+3]=1, nxt[i]=i+3;

	}

	

	nxt[n-1]=n;

	for(i=0; i<n; i++){

		if(nxt[i]){

			int j=i-1;

			while(j>=0 && !nxt[j]){

				nxt[j]=nxt[i];

				j--;

			}

			

		}

	}

	

	int ans=0;

	for(i=0; i<n; i++){

		ans+=n-nxt[i];

	}

	cout<<ans<<endl;



	return 0;

}