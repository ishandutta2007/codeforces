#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    string s;
    cin >> n >> s;
    
    int t = 0;
    int max_h = 0;
    int x[n], h[n];
    for(int i = 0; i < n; i++) {
        x[i] = (i ? x[i-1] : -1) + 1;
        if(s[i] == '[') {
            t++;
            h[i] = t;
        } else {
            h[i] = t;
            t--;
            if(s[i-1] == '[') x[i] += 3;
        }
        max_h = max(max_h, h[i]);
    }
    
    vector<vector<char> > pic (2*max_h + 1, vector<char>(x[n-1] + 1, ' '));
    for(int i = 0; i < n; i++) {
        int len = max_h - h[i]; 
        for(int dh = -len; dh <= len; dh++) {
            pic[max_h + dh][x[i]] = '|';
        }
        int j = 1;
        for(int t = 0; t < 2; t ++) {
            j *= -1;
            pic[max_h + j * (len + 1)][x[i]] = '+';
            pic[max_h + j * (len + 1)][x[i] + (s[i] == '[' ? 1 : -1)] = '-';
        }
    }
    
    for(int y = 0; y < 2*max_h + 1; y++) {
        for(int xx = 0; xx <= x[n-1]; xx++) 
            cout << pic[y][xx];
        cout << '\n';
    }
    
    return 0;
}