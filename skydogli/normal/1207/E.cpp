#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	putchar('?');
	for(int i=1;i<=100;++i)printf(" %d",i);
	cout<<endl;
	cin>>a;
	putchar('?');for(int i=1;i<=100;++i)printf(" %d",i<<7);
	cout<<endl;
	cin>>b;
	printf("! %d\n",((a>>7)<<7)|(b&((1<<7)-1)));
	return 0;
}