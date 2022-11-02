#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char s[NN], t[NN];



int main() {

	int n,i,j;

	cin>>n;

	

	scanf("%s %s", s, t);

	int ans=0;

	for(i=0; i<n; i++){

		int a=s[i]-'0';

		int b=t[i]-'0';

		if(a<b) swap(a, b);

		ans+=min(a-b, (b+10-a)%10);

	}

	cout<<ans<<endl;





	return 0;

}