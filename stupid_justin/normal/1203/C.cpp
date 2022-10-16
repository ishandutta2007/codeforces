#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
long long gcd(long long a,long long b)
{
	if (a%b==0) return b;
	return gcd(b,a%b);	
} 
long long f(long long d)
{
    long long num=0;
    for(long long i=1;i<sqrt(d);i++)
    {
        if(d%i==0)
        	num++;
    }
    num*=2;
    long long s=floor(sqrt(d));
    if(d==s*s) num++;
    return num;
}
long long a[N];
int main()
{
	long long t;
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if (n==1) t=a[0];
	else if (n==2) t=gcd(a[1],a[0]);
	else
	{
		t=gcd(a[1],a[0]);
		for (int i=2;i<n;i++) t=gcd(a[i],t);
	}
	cout<<f(t)<<endl;
}