#include <iostream>
using namespace std;

int main()
{
	int cases[6]; 
	int a, b, c;
	cin>>a>>b>>c;
	cases[0] = a + b + c;
    cases[1] = a + b * c;
    cases[2] = (a + b) * c;
    cases[3] = a * b + c;
    cases[4] = a * b * c;
    cases[5] = a * (b + c);
    cout<<max(cases[0], max(cases[1], max(cases[2], max(cases[3], max(cases[4], cases[5])))))<<endl;
	return 0;
}