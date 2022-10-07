#include <iostream>
#include <string>
#include <map>
using namespace std;
string tl(string s)
{for (int i=0; i<s.length(); i++)
if (s[i]>96) s[i]-=32;
return s;
}
int main (){
    map <string, int> M;
    int n;
    cin >> n;
    M["polycarp"] = 1;
    int an = 1;
    for (int i = 0; i < n; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        M[tl(a)] = M[tl(c)] + 1;
        if (M[tl(a)]>an) an=M[tl(a)];
    }
    cout << an+1 << endl;
return 0;
}