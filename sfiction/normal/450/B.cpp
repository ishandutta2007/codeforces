/*
ID: Sfiction
OJ: CF
PROB: 450B
*/
#include <iostream>

using namespace std;

const long long MOD=1E9+7;

int main(){
	long long f[6];
	cin >> f[1] >> f[2];
	f[0]=f[1]-f[2];
	f[3]=f[2]-f[1];
	f[4]=-f[1];
	f[5]=-f[2];

	int n;
	cin >> n;
	cout << (f[n%6]+10*MOD)%MOD;
	return 0;
}