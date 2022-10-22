#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        ll s, a, b, c;
        cin >> s >> a >> b >> c;
        s /= c;
        cout << s / a * b + s << endl;
    }
}