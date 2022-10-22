#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        string s;
        cin >> n >> s;
        int les[200005];
        bool first[200005];
        fill(les, les + n + 1, 10);
        fill(first, first + n, false);
        for(int i = n - 1; i >= 0; i--){
            les[i] = min(s[i] - '0', les[i + 1]);
        }
        int m = 10;
        for(int i = 0; i < n; i++){
            if(s[i] - '0' > les[i]) m = min(m, s[i] - '0');
        }
        for(int i = 0; i < n; i++){
            if(s[i] - '0' == les[i] && s[i] - '0' <= m) first[i] = true;
        }
        int l = 0;
        bool able = true;
        for(int i = 0; i < n; i++){
            if(first[i]) continue;
            if(s[i] - '0' < l){
                cout << '-' << endl;
                able = false;
                break;
            }
            l = s[i] - '0';
        }
        if(!able) continue;
        for(int i = 0; i < n; i++){
            if(first[i]) cout << 1;
            else cout << 2;
        }
        cout << endl;
    }
}