#include <iostream>
#include <iomanip>

using namespace std;

#define ld long double

int main()
{
    ld a,b,c,s;
    cin >> s >> a >> b >> c;
    cout << fixed;
    if (a+b+c==0) cout << s << " 0 0"; else
    cout << setprecision(18) << s*(a/(a+b+c))<< " " << s*(b/(a+b+c))<< " " << s*(c/(a+b+c));
    return 0;
}