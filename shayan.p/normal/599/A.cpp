#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main()
{
	int a,b,c;
	int A[4];
	cin>>a>>b>>c;
	A[0]=a+b+c;
	A[1]=a+a+b+b;
	A[2]=a+a+c+c;
	A[3]=b+b+c+c;
	for(int i=1;i<4;i++)
	if(A[0]>A[i])
	A[0]=A[i];
	cout<<A[0];
}