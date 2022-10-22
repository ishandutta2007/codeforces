#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> l(4), s(4), r(4), p(4);

    for(int i = 0; i < 4; i++)
        cin >> l[i] >> s[i] >> r[i] >> p[i];

    bool ans = false;
    for(int i = 0; i < 4; i++)
        if(p[i] && (l[i] || s[i] || r[i] ||
            l[(i + 1) % 4] || s[(i + 2) % 4] || r[(i + 3) % 4]))ans = true;

    if(ans)cout << "YES";
    else cout << "NO";

}