#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int t;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        int p1 = s.find_first_of('0');
        int p2 = s.find_last_of('1');
        p1 = p1 == string::npos ? s.size() : p1 + 1;
        p2 = p2 == string::npos ? -1 : p2 - 1;
        cout << p1 - p2 - 1 << endl;
    }
	return 0;
}