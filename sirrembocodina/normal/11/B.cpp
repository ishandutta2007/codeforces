#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main(){       
	long long c,n,x;
	cin>>x;
	x=abs(x);
	n=floor(sqrt(8*x+1));
	while((n*n<8*x+1)||((n*n)%16!=(8*x+1)%16))
		n++;
	c=(n-1)/2;
	cout<<c;
}