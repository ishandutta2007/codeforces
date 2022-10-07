//http://codeforces.com/problemset/problem/13/A steven
#include <iostream> //ray, your turn scott. Steven's prboelm looks good. 

using namespace std; //steven, fuck this. scott you are bad

typedef long long ll;int solve (int left, int tot){    int x = 0;	while (tot)	{		x += tot % left;		tot /= left;	}	return x;}int gcf (int a, int b){	return ((b == 0) ? a : gcf (b, a % b));}int main(){	int num, den;	int x; cin >> x;	num = 0;	for (int i = 2; i <= x - 1; i++)	{		num += solve (i, x);	}		den = x - 2;	int g = gcf (num, den);	cout << num / g << "/" << den / g << "\n";	return 0;} // scott

int A; //ray
int B; //steven i think we're done.