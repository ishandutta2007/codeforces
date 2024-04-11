#include<iostream>
#include<complex>
using namespace std;
long long cross(complex<long long> a,complex<long long > b)
{
    return (conj(a)*b).imag();
}
int main()
{
    long long  x,y;
	complex <long long> a,b,c;
	cin>>x>>y;
    a.real(x);
    a.imag(y);
    cin>>x>>y;
    b.real(x);
    b.imag(y);
    cin>>x>>y;
    c.real(x);
    c.imag(y);
    	complex<long long> A=a-b,B=c-b;
if((A.real()*A.real())+(A.imag()*A.imag())==(B.real()*B.real())+(B.imag()*B.imag())&&cross(A,B)!=0)
	cout<<"Yes";
	else
	cout<<"No";
}