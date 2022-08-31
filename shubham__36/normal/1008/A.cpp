#include <iostream>
#include <algorithm>
#include <cmath>
//#include <vector>
//#include <string>
//#include <iomanip>

using namespace std;

int main()
{
    string s;
    bool b=true;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(!b && !(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')) {
            b=false;
            break;
        }
        else if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='n'){
            b=true;
        }
        else b=false;
    }
    if(b) cout << "YES";
    else cout << "NO";

}