#include<iostream>
using namespace std;
void print( int n, int a ) {
	for(int b=0;b<n-a;b++)cout<<"  ";	   
	for(int i=0;i<a;i++)cout<<i<<" ";  //012~(n-1)
	for(int i=a;i>0;i--)cout<<i<<" "; //n~0
	cout<<0<<endl;
}
int main()
{
	int n;
	cin>>n;
	for(int a=0;a<n;a++)print(n,a);
	for(int a=n;a>=0;a--)print(n,a);
	return 0;
}