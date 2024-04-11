//In the name of God
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		int now;
		cin >> now;
		cout << ((now % 2) ^ 1) << endl;
	}
	return 0;
}