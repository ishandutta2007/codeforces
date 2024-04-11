#include<bits/stdc++.h>



#define NN 111111

#define inf 1000000000

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;





int main(){

	int n,num1=0,num2=0,ans,j;

	char str[250];

	cin>>n;

	cin>>str;

	for(int i=0;i<n;i++)

		if(str[i]=='x') num1++;

	

	

	ans=abs(num1-n/2);

	printf("%d\n",ans);

	if(ans==0) {cout<<str; return 0;}

	j=0;

	if(num1>n/2) {

		for(int i=0;i<n;i++){

			if(j==ans) break;

			if(str[i]=='x') {str[i]='X'; j++;}

			}

		cout<<str;

	}

	else {

		for(int i=0;i<n;i++){

			if(j==ans) break;

			if(str[i]=='X') {str[i]='x'; j++;}

			}

		cout<<str;

	}

	return 0;

}