#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		long long n,k;
		cin >> n >> k;
		if(n%2==0)
		{
			cout << ((k-1)%n)+1 << "\n";
		}
		else
		{
			int cnt=((k-1)/((n-1)/2));
			k+=cnt;
			cout << ((k-1)%n)+1 << "\n";
		}
	}
	return 0;
}