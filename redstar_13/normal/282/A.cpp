#include<bits/stdc++.h>



using namespace std;



int main(){

	int n,ans=0;

	cin>>n;

	char str[5];

	for(int i=0;i<n;i++){

		scanf("%s",str);

		if(strstr(str,"++")!=NULL)  ans++;

		else ans--;

	}

	printf("%d",ans);

	return 0;

}