#include <iostream>
#include <cstddef>
#include <utility>
#include <algorithm>
#include <string>


using namespace std;
int main(){
    long long n;
    cin >> n;
    long long* a = new long long[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long c = 0;
    long long* b = new long long[n];
    b[0] = 1;
	for (long long i = 1; i < n; i++){
		b[i] =( b[i - 1] * 2) % 1000000007;
	} 
    sort(&a[0], &a[n]);
	for (long long i = 0; i < n; i++){
		c += (a[i] * (b[i] - b[n - i - 1])) % 1000000007;
	}
	int m;
	m = 1000000007;
	c = c % m;
	while (c < 0){
		c += m;
	}
    cout << c;
    return 0;
}