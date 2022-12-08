#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	bool ok = true;
	if (A > N || B > N || C > N) ok = false;
	int numc = A + B - C;
	numc = N - numc;
	if (numc <= 0) ok = false; //at least one fail
	if (C > A || C > B) ok = false;
	if (ok) cout << numc << endl;
	else cout << -1 << endl;
	cin >> A;
	
}