#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



pii pos[NN];



int cmp(pii u, pii v){

	if(abs(u.first)==abs(v.first)) return abs(u.second)<abs(v.second);

	return abs(u.first)<abs(v.first);

}



int main() {

	int n,i,j;

	cin>>n;

	int ans=0;

	for(i=0; i<n; i++) {	

		scanf("%d%d", &pos[i].first, &pos[i].second);

		if(pos[i].first==0 || pos[i].second==0) ans+=4;

		else ans+=6;

	}

	

	sort(pos, pos+n, cmp);

	

	cout<<ans<<endl;

	for(i=0; i<n; i++){

		int x=pos[i].first, y=pos[i].second;

		

		char d1=(x>0)?'R':'L';

		char d2=(y>0)?'U':'D';

		

		x=abs(x), y=abs(y);

		if(x) printf("1 %d %c\n", x, d1);

		if(y) printf("1 %d %c\n", y, d2);

		puts("2");

		if(y) printf("1 %d %c\n", y, 'U'+'D'-d2);

		if(x) printf("1 %d %c\n", x, 'R'+'L'-d1);

		puts("3");

	}



	return 0;

}