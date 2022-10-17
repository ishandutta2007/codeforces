#include <iostream>
using namespace std;

string a, b;
int d[100005];

int main(){
    cin >> a >> b;
    
    for(int i=0; i<a.length(); i++)
        d[i] += a[a.length() - 1 - i] == '1';

    for(int i=0; i<b.length(); i++)
        d[i] -= b[b.length() - 1 - i] == '1';

    for(int i = 100000; i>=2; i--){
        if(d[i] == 0) continue;
        if(d[i] >= 2){
            cout << ">" << endl;
            return 0;
        }
        if(d[i] <= -2){
            cout << "<" << endl;
            return 0;
        }
        d[i-1] += d[i];
        d[i-2] += d[i];
        d[i] = 0;
    }

    double res = 1.618033988749894848 * d[1] + d[0];
    if(res > 1e-9) cout << ">" << endl;
    else if (res < -1e-9) cout << "<" << endl;
    else cout << "=" << endl;
    return 0;
}