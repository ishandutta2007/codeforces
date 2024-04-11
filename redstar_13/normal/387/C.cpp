#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char s[NN], tmp[NN];

string arr[NN];



int main() {



	

	scanf("%s" ,s);

	int n=strlen(s), i,j;

	

	int nn=0;

	string tmp;

	

	for(i=0; i<n; ){

		while(s[i+1]=='0') {

			arr[nn]+=s[i];

			i++;

		}

		arr[nn]+=s[i];

		i++;

		nn++;

	}

	

	int st=0;

	for(i=0; i<nn; i++){

		if(i==0) tmp=arr[i];

		else tmp+=arr[i];

		if(tmp.size()<arr[i+1].size()) st=i+1;

		else if(tmp.size()==arr[i+1].size() && tmp<arr[i+1])  st=i+1;

	}

	

	cout<<nn-st<<endl;

	return 0;

}