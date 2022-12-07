#include<iostream>
#define ll long long

using namespace std;

ll n,l;
ll a[40];
ll rs;
ll b[5000];

int main() {
	cin>>n>>l;
	for(int i=0; i<5000; i++)
	{
	    for(int j=0; j<5000; j++)
	    {
	        b[i] = j;
	    }
	}
	for (int i=0; i<n; i++) 
		cin>>a[i];
		
	for (int i=1; i<=30; i++) {
		if (!a[i]) a[i]=(1e18);
		a[i]=min(a[i], a[i-1]*2);
	}
	
	for (int i=0; i<=30; i++) {
		if (l>>i & 1) {
			rs+=a[i];
		} else rs=min(rs, a[i]);
	}
	cout<<rs;
	return 0;
}