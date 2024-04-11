#include<bits/stdc++.h>

#define NN 110010



using namespace std;

char str[NN];



int main(){

	int a[5],ans=0;

	cin>>a[1]>>a[2]>>a[3]>>a[4];

	cin>>str;

	for(int i=0;str[i]!='\0';i++) ans+=a[str[i]-'0'];

	printf("%d",ans);

	return 0;

}