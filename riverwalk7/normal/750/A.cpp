#include <iostream>
using namespace std;
int n, k;
int main() {
	// your code goes here
	cin>>k>>n;
	int x=240-n;
	for(int i=1; i<=k; i++)
	{
	    x-=(5*i);
	    if(x<0)
	    {
	        cout<<i-1<<endl;
	        return 0;
	    }
	}
	cout<<k<<endl;
	return 0;
}