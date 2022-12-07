#include <iostream>
using namespace std;
int n;
int x;
int main() {
	// your code goes here
	cin>>n;
	string b;
	int a;
	for(int i=0; i<n; i++)
	{
	    cin>>a>>b;
	    if(b=="East"||b=="West")
	    {
	        if(x==0||x==20000)
	        {
	            cout<<"NO"<<endl;
	            return 0;
	        }
	    }
	    else if(b=="North")
	    {
	        if(x<a)
	        {
	            cout<<"NO"<<endl;
	            return 0;
	        }
	        else
	        {
	            x-=a;
	        }
	    }
	    else if(b=="South")
	    {
	        if(x>(20000-a))
	        {
	            cout<<"NO"<<endl;
	            return 0;
	        }
	        else
	        {
	            x+=a;
	        }
	    }
	}
	if(x==0)
	{
	    cout<<"YES"<<endl;
	}
	else
	{
	    cout<<"NO"<<endl;
	}
}