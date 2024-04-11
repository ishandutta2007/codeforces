#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <cmath>
#define REP(i,n) for(int i=0;i<n;i++)
#include <algorithm>

using namespace std;

int N;
#define MN 100000
#define MA 10000000
int arr[100100];

int main(){
	cin>>N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	//reading problem
	// same

	long long tot = 0;

	// reading
	//fuck you
	tot = 0;
	sort (arr, arr + N);

	tot = 0;

	//you just add every pair first
	for (int i = 0; i < N; ++i) {
		tot += ((N - 1) - 2 * (N - 1 - i)) * (long long) arr[i];
	}

	tot*=2;

	;
	for (int i = 0; i < N; i++) tot += arr[i]; // divide by N to get ans


	long long g = __gcd(tot, (long long) N);
	
	long long num=tot/g;
	long long den = N / g;
	cout << num << " " << den << "\n";
	{}
	return 0;
}