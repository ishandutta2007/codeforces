#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int x,y,z,x1,x2;
    cin >> x >> y >> z;
    string s1,s2;
    if(x>y){
        s1="0";
        s2="1";
        x1=x;
        x2=y;
    }
    else{
       s1="1";
        s2="0";
        x1=y;
        x2=x;
    }
    string s="";
    while(z>=2){
        if(z%2==0){
        s.append(s1);
        x1--;
        z--;
        }
        else{
        s.append(s2);
        x2--;
        z--;
        }
    }
    if(z == 1){
        while(x2--){
            s.append(s2);
        }
        z--;
    }
    if(z == 0){
        while(x1--){
            s.append(s1);
        }
    }
    cout << s;
    return 0;
}