#include <iostream>
#include <string>
using namespace std;

string s;

int main(){
    cin >> s;
    if(s.substr(0, 4) == "http"){
	cout << "http://";
	s = s.substr(4);
    }else{
	cout << "ftp://";
	s = s.substr(3);
    }
    int v = s.substr(1).find("ru");
    cout << s.substr(0, v + 1) << ".ru";
    if(v != s.size() - 3) cout << "/" << s.substr(v + 3);
    cout << endl;
    return 0;
}