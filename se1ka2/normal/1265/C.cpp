#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int p[400005];
        for(int i = 0; i < n; i++) cin >> p[i];
        int g = 0;
        for(; g < n; g++){
            if(p[g] != p[g + 1]) break;
        }
        int s = 0;
        for(; s + g < n; s++){
            if(p[s + g] != p[s + g + 1] && s > g + 1) break;
        }
        int b = 0;
        for(int i = n / 2 - 1; i >= 0; i--){
            if(p[i] != p[i + 1]){
                b = i - s - g;
                break;
            }
        }
        if(s > g + 1 && b > g + 1) cout << g + 1 << " " << s << " " << b << endl;
        else cout << "0 0 0" << endl;
    }
}