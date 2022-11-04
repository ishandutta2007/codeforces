#include<bits/stdc++.h>

using namespace std;

#define M 100005

char s[M];

int main(){
	
//	freopen("in.txt", "r", stdin);
	
	int n, i;
	
	cin >> s;
	
	n = strlen(s); cout << 4 << endl;
	
	cout << "L " << n - 1 << endl;
	n += n - 2;
	
	cout << "R " << n - 1 << endl;
	n += 1;
	
	cout << "L " << n - 1 << endl;
	n += n - 2;
	
	cout << "L 2" << endl;
	
	return 0;
}