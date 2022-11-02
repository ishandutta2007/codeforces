#include<bits/stdc++.h>



using namespace std;



char a[1010];

int i, j, l, ok, flag=1;

int cnt[300];



int main(){

	

//	freopen("in.txt", "r", stdin);

	

	scanf("%s", a);

	l=strlen(a);

	

	ok=1;

	for(i=0; i<l; i++) {

		cnt[a[i]]++;

	}

	

	int ans=0;

	for(i='a'; i<='z'; i++){

		if(cnt[i]&1) ans++;

	}

	if(ans==0 || ans&1) puts("First");

	else puts("Second");

	return 0;

}