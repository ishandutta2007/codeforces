#include <iostream>

using namespace std;

int n,a,b,c;

int main(){
	cin>>n>>a>>b>>c;

	n*=2;
	int rs=0;
	for (int i=0; i<=a; i++)
		for (int j=0; j<=b; j++)
			if ((n-i-2*j)%4==0&&(n-i-2*j)/4<=c&&(n-i-2*j)>=0) rs++;
	cout<<rs<<endl;

	return 0;
}