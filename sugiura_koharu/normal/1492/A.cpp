#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		long long a,b,c,d;
		cin >> a >> b >> c >> d;
		long long B,C,D;
		B=a/b*b+b;
		C=a/c*c+c;
		D=a/d*d+d;
		while(B-b>=a) B-=b;
		while(C-c>=a) C-=c;
		while(D-d>=a) D-=d;
		cout << min(B-a,min(C-a,D-a)) << "\n";
	}
	return 0;
}