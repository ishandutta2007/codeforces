    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int a, b, c, x, y, z;
        cin >> a >> b >> c >> x >> y >> z;
        if(a <= x && a + b <= x + y && a + b + c <= x + y + z)
            cout << "YES\n";
        else
            cout << "NO\n";
    }