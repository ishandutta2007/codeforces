#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[22];

string ans;



int main() {

	int n,i,j,k=0;

	cin>>n;

	string tmp="O-|-OOOO";

	if(n==0) {cout<<tmp<<endl; return 0;}

	while(n){

		a[k++]=n%10;

		n/=10;

	}

	

	for(i=0; i<k; i++){

		ans=tmp;

		if(a[i]>=5) swap(ans[0], ans[1]);

		swap(ans[3+a[i]%5], ans[3]);

		cout<<ans<<endl;

	}





	return 0;

}