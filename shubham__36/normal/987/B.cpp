#include <iostream>

using namespace std;

int main()
{
    long long int x,y;
    cin >> x >> y;
    if(x == y) cout << "=" << endl;
    else if(x > 2 && y > 2) {
        if(x > y) cout << "<" << endl;
        else cout << ">" << endl;
    }
    else if(x <= 2 && y <= 2){
        if(x > y) cout << ">" << endl;
        else cout << "<" << endl;
    }
    else if(x <= 2){
        if(x == 1) cout << "<" << endl;
        else if(y == 3) cout << "<" << endl;
        else if(y == 4) cout << "=" << endl;
        else cout << ">" << endl;
    }
    else if(y <= 2){
        if(y == 1) cout << ">" << endl;
        else if(x == 3) cout << ">" << endl;
        else if(x == 4) cout << "=" << endl;
        else cout << "<" << endl;
    }
    return 0;
}