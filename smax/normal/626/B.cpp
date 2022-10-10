#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	string s;
	cin >> s;
	int r=0,g=0,b=0;
	for(int i=0;i<n;i++){
		if(s[i] == 'R') r++;
		else if (s[i] == 'G') g++;
		else b++;
	}
	if(r > 0 && g > 0 && b > 0){
		cout << "BGR\n";
		return 0;
	}
	if(r && !g && !b){
		cout << "R\n";
		return 0;
	}
	if(g && !r && !b){
		cout << "G\n";
		return 0;
	}
	if(b && !g && !r){
		cout << "B\n";
		return 0;
	}
	if(b == 0 && r*g || (b > 0 && r+g >= 2)) cout << "B";
	if(g == 0 && b*r || (g > 0 && r+b >= 2)) cout << "G";
	if((r == 0 && b*g) || (r > 0 && b+g >= 2)) cout << "R";
	return 0;
}